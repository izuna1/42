/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_reader.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljeanner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 17:43:53 by ljeanner          #+#    #+#             */
/*   Updated: 2016/12/08 17:36:33 by ljeanner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_list		*ft_file_reader(char *filename)
{
	int		fd;
	int		chars;
	int		maxchars;
	t_list	*entry;

	entry = NULL;
	chars = 0;
	fd = open(filename, O_RDONLY);
	entry = ft_cut_tetriminos(fd, &chars);
	maxchars = (ft_lstcount(entry) * 21) - 1;
	if (chars != maxchars)
		return (NULL);
	if (close(fd) == -1)
		return (NULL);
	if (ft_check_tetriminos(entry) == FALSE)
		return (NULL);
	return (entry);
}

t_list		*ft_cut_tetriminos(int fd, int *chars)
{
	char	buffer[BUF_SIZE + 1];
	char	c;
	int		reader;
	t_list	*head;
	t_list	*tmp;

	head = NULL;
	c = 0;
	if ((reader = read(fd, buffer, BUF_SIZE)) < 0)
		return (NULL);
	*chars += reader;
	while (reader > 0)
	{
		buffer[reader] = '\0';
		tmp = ft_lstpushend(tmp, buffer, reader + 1);
		if (!head)
			head = tmp;
		reader = read(fd, &c, 1);
		if (c != '\n' && c)
			return (NULL);
		*chars += reader;
		reader = read(fd, buffer, BUF_SIZE);
		*chars += reader;
	}
	return (head);
}

t_bool		ft_check_tetriminos(t_list *tetriminos_list)
{
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = tetriminos_list;
	while (tmp != NULL)
	{
		if (ft_containsinvalidchars(tmp->content) == TRUE)
			return (FALSE);
		tmp = tmp->next;
		i++;
	}
	return (TRUE);
}

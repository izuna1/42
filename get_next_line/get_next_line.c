/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljeanner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 15:33:55 by ljeanner          #+#    #+#             */
/*   Updated: 2017/01/04 17:30:02 by ljeanner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char				*str_append(char *src, const char c)
{
	char			*dst;
	size_t			i;
	size_t			len;

	if (!src || !c)
		return (NULL);
	len = ft_strlen(src);
	if (!(dst = ft_strnew(len + 1)))
		return (NULL);
	i = -1;
	while (++i < len)
		dst[i] = src[i];
	dst[i] = c;
	free(src);
	return (dst);
}

size_t				str_cpytil(char **line, const char *src, const char c)
{
	int				i;
	int				j;

	i = 0;
	j = 0;
	while (src[i] && src[i] != c)
		i++;
	if (!(*line = ft_strnew(i)))
		return (0);
	while (src[j] && j < i)
	{
		if (!(*line = str_append(*line, src[j])))
			return (0);
		j++;
	}
	return (i);
}

static t_list		*get_curr_file(t_list **file, int fd)
{
	t_list			*node;

	node = *file;
	while (node)
	{
		if ((int)node->content_size == fd)
			return (node);
		node = node->next;
	}
	ft_lstadd(file, ft_lstnew("\0", fd));
	return (*file);
}

int					get_next_line(const int fd, char **line)
{
	static	t_list	*fds;
	t_list			*node;
	char			buffer[BUF_SIZE + 1];
	int				reader;
	int				i;

	if (fd < 0 || !line || read(fd, buffer, 0) < 0)
		return (-1);
	node = get_curr_file(&fds, fd);
	while ((reader = read(fd, buffer, BUF_SIZE)))
	{
		buffer[reader] = '\0';
		if (!(node->content = ft_strjoin(node->content, buffer)))
			return (-1);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	if (reader < BUF_SIZE && ft_strlen(node->content) == 0)
		return (0);
	if ((i = str_cpytil(line, node->content, '\n')) <
			(int)ft_strlen(node->content))
		node->content += (i + 1);
	else
		ft_strclr(node->content);
	return (1);
}

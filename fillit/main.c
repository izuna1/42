/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljeanner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 17:50:58 by ljeanner          #+#    #+#             */
/*   Updated: 2016/12/08 16:27:07 by ljeanner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int ac, char **av)
{
	int			tetri_count;
	int			cnt;
	t_list		*str_list;
	t_tetris	*tts;
	t_map		*map;

	if (ac != 2)
		return (ft_printerror("usage: ./fillit tetriminos_file\n"));
	if (!(str_list = ft_file_reader(av[1])))
		return (ft_printerror("error\n"));
	if ((tetri_count = ft_lstcount(str_list)) > 26)
		return (ft_printerror("error\n"));
	tts = (t_tetris *)ft_memalloc(sizeof(t_tetris) * tetri_count);
	cnt = -1;
	while (++cnt < tetri_count)
	{
		if (!(ft_createtetris((char *)str_list->content, 'A' + cnt, &tts[cnt])))
			return (ft_printerror("error\n"));
		str_list = str_list->next;
	}
	map = ft_solve(tts, tetri_count);
	ft_printmap(map);
	ft_freemap(map);
	return (0);
}

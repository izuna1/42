/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljeanner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 17:34:19 by ljeanner          #+#    #+#             */
/*   Updated: 2016/12/08 17:19:07 by ljeanner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "./libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>

# define BUF_SIZE 20
# define MAX_PATTERNS 19

typedef struct	s_point
{
	int x;
	int y;
}				t_point;

typedef struct	s_tetris
{
	char		id;
	t_point		hash_pos[4];
	t_point		offset;
}				t_tetris;

typedef struct	s_map
{
	int			size;
	char		**grid;
}				t_map;

t_bool			ft_containsinvalidchars(char *str);
t_point			*ft_gethashlocations(char *pattern, t_point *hash_array);
char			*ft_getpattern(char *str);
t_bool			ft_checkpattern(char *pattern);
int				ft_getmostleft(char *str);

t_list			*ft_file_reader(char *filename);
t_list			*ft_cut_tetriminos(int fd, int *chars);
t_bool			ft_check_tetriminos(t_list *tetriminos_list);

t_map			*ft_createmap(int size);
void			ft_freemap(t_map *map);
void			ft_printmap(t_map *map);
void			ft_resetmap(t_map *map);

t_bool			ft_createtetris(char *str, char id, t_tetris *tt);
t_bool			ft_caninsert(t_map *map, t_tetris *tts);
t_bool			ft_place(t_map *map, t_tetris *tts);
void			ft_remove(t_map *map, t_tetris *tts);
int				ft_move(t_map *map, t_tetris *tts, t_point *dest);

int				ft_solvemap(t_map *map, t_tetris *tts, int i);
t_map			*ft_solve(t_tetris *tts, int count);

int				ft_sqrt(int nb);
t_point			*ft_newpoint(int x, int y);
int				ft_printerror(char *str);
#endif

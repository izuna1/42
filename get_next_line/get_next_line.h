/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljeanner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 15:35:47 by ljeanner          #+#    #+#             */
/*   Updated: 2017/01/04 17:51:19 by ljeanner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft.h"
# include <stdlib.h>
# include <unistd.h>

# define BUF_SIZE 8

char	*str_append(char *src, const char c);
size_t	str_cpytil(char **dest, const char *src, const char c);
int		get_next_line(const int fd, char **line);

#endif

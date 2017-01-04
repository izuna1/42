# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ljeanner <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/07 19:03:25 by ljeanner          #+#    #+#              #
#    Updated: 2016/12/08 17:39:25 by ljeanner         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = main.c \
	  ft_checker.c \
	  ft_file_reader.c \
	  ft_map.c \
	  ft_solver.c \
	  ft_tetris.c \
	  ft_utils.c \

HEADER = fillit.h

WWW = gcc -Wall -Wextra -Werror

LIB = ./libft/libft.a

OBJ = $(SRC:.c=.o)

%.o:%.c
	@$(WWW) -o $@ -c $< -I $(HEADER)

default: all

.PHONY: all clean fclean re

all:$(NAME)

$(NAME):
	@(cd libft; make fclean)
	@(cd libft; make)
	@(cd libft; make clean)
	@$(WWW) -c $(SRC)
	@$(WWW) $(LIB) $(OBJ) -o $(NAME)
	@echo "Fillit created."

clean:
	@/bin/rm -f $(OBJ)

fclean: clean
	@(cd libft; make fclean)
	@/bin/rm -f $(NAME)

re:		fclean all

#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lstepany <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/03 12:50:03 by lstepany          #+#    #+#              #
#    Updated: 2020/11/03 12:50:05 by lstepany         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

SRC = main.c key_control.c drow_line.c list_isometrik.c list_plan.c get_map.c final.c
OBJ = main.o key_control.o drow_line.o list_isometrik.o list_plan.o get_map.o final.o
FLAGS = -Wall -Wextra -Werror
all: fdf
fdf: $(OBJ)
	make -C libft
	gcc  $(FLAGS) -g -o fdf $(OBJ) -L libft/ -lft -I /usr/local/include  -L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit

$(OBJ): %.o: %.c fdf.h
	clang $(FLAGS) -c $<

libft:
	make -C libft
clean:
	make fclean -C libft
	rm -rf *~ *.o
fclean: clean
	rm -f fdf
re:fclean make

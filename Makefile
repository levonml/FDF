
SRC = main.c key_control.c drow_line.c list_isometrik.c list_plan.c get_map.c final.c
OBJ = main.o key_control.o drow_line.o list_isometrik.o list_plan.o get_map.o final.o
FLAGS = -Wall -Wextra -Werror
all: fdf
fdf: $(OBJ)
	make -C libft
	clang  $(FLAGS) -o fdf -L libft/ -lft -I /usr/local/include $(OBJ) -L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit

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

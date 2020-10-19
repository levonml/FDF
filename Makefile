make:
	make -C libft/ fclean && make -C libft/
#	clang -Wall -Wextra -Werror -I libft/includes -o main.o -c main.c
#	clang -o fdf main.c get_map.c libft/get_next_line.o -I libft/includes\
#	-L libft/ -lft -I /usr/local/include -L /usr/local/lib/ -lmlx  \
#	-L /usr/lib/x86_64-linux-gnu -lXext -L /usr/lib/x86_64-linux-gnu -lX11
	clang  -o fdf main.c get_map.c drow_line.c libft/get_next_line.o -I libft/includes -L libft/ -lft -I /usr/local/include -L /usr/local/lib/ -lmlx -\
L /usr/lib/x86_64-linux-gnu -lXext -L /usr/lib/x86_64-linux-gnu -lX11
fclean:
	rm -rf *~ *.o

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstepany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 19:42:23 by lstepany          #+#    #+#             */
/*   Updated: 2020/10/27 21:18:26 by lstepany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "fdf.h"
#include <fcntl.h>

#include<stdio.h>

void	listdel(t_list *head)//, t_iso *head1)
{
	t_list	*temp;
	//	t_list *temp1;

	//temp1 = temp;
	while (head)
	{
		temp = head;
		head = head->next;
		free(temp->content);
		free(temp);
		temp = NULL;
	}
	/*while (head1)
	  {
	    temp1 = head1;
	    head1 = head1->next;
	    free(temp1);
	    temp = NULL;
	    }*/
}

t_iso	*next_row(t_iso *ord)
{
	size_t	i;

	i = 0;
	while (i < ord->content_size)
	{
		ord = ord->next;
		i++;
	}
	return (ord);
}

void	drow_iso(t_param *param)
{
	t_iso	*abs;
	t_iso	*ord;

	mlx_clear_window(param->data.mlx_ptr, param->data.win_ptr);
	abs = param->iso;
	ord = next_row(param->iso);
	final(abs, ord, param->data);
        // listdel(param->map);
}

void	drow_plan(t_param *param)
{
	t_iso	*abs;
	t_iso	*ord;

	mlx_clear_window(param->data.mlx_ptr, param->data.win_ptr);
	abs = param->plan;
	ord = next_row(param->plan);
	final(abs, ord, param->data);
	//		listdel(param->map);
}

int		main(int argc, char **argv)
{
	t_param	*param;

	param = NULL;
	if (argc < 2)
	{
		ft_putstr("argument is missing\nusage: ./fdf file_name\n");
		return (0);
	}
		if (!(param = (t_param *)malloc(sizeof(param))))
		return (0);
	if ((param->fd = open(argv[1], O_RDONLY)) && param->fd == -1)
	{
		ft_putstr("file opening error");
		return (0);
	}
	param->map = get_map(param->fd, param->data, param->map, param->map1);
	close(param->fd);
	param->data.mlx_ptr = mlx_init();
	param->data.win_ptr = mlx_new_window(param->data.mlx_ptr,\
	1000, 1000, "fdf");
	param->iso = list_iso(param->map, param->data, param->iso, param->map1);
	param->plan = list_plan(param->map, param->data, param->plan, param->map1);
	mlx_key_hook(param->data.win_ptr, key_control, param);
	//		printf("param->map = %d\n", ((int *)param->map->content)[3]);
	//listdel (param->map, param->iso);
	//listdel (param->map, param->plan);
	//free(param);
	mlx_loop(param->data.mlx_ptr);
	//		listdel (param->map, param->iso);
		//exit(0);
		return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstepany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 19:42:23 by lstepany          #+#    #+#             */
/*   Updated: 2020/11/03 12:15:47 by lstepany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "fdf.h"
#include <fcntl.h>

void	listdel(t_list **head)
{
	t_list *temp;
	t_list *next;

	temp = *head;
	while (temp)
	{
		next = temp->next;
		free(temp->content);
		free(temp);
		temp = next;
	}
}

t_iso	*next_row(t_iso *ord)
{
	size_t	i;

	if (ord == NULL)
		return (NULL);
	i = 0;
	while (ord->content_size)
	{
		ord = ord->next;
		i++;
	}
	return (ord->next);
}

void	drow_iso(t_param *param)
{
	t_iso	*abs;
	t_iso	*ord;

	mlx_clear_window(param->data.mlx_ptr, param->data.win_ptr);
	abs = param->iso;
	ord = next_row(param->iso);
	final(abs, ord, param->data);
}

void	drow_plan(t_param *param)
{
	t_iso	*abs;
	t_iso	*ord;

	mlx_clear_window(param->data.mlx_ptr, param->data.win_ptr);
	abs = param->plan;
	ord = next_row(param->plan);
	final(abs, ord, param->data);
}

int		main(int argc, char **argv)
{
	t_param	*param;

	if (argc != 2)
	{
		ft_putstr("wrong number of arguments\nusage: ./fdf file_name\n");
		return (0);
	}
	if (!(param = (t_param *)malloc(sizeof(*param))))
		return (0);
	if ((param->fd = open(argv[1], O_RDONLY)) && param->fd == -1)
	{
		ft_putstr("file opening error\n");
		return (0);
	}
	param->map = get_map(param->fd, param->data, param->map, param->map1);
	close(param->fd);
	param->data.mlx_ptr = mlx_init();
	param->data.win_ptr = mlx_new_window(param->data.mlx_ptr,\
	1500, 1500, "fdf");
	param->iso = list_is(param->map, param->data, param->iso, param->plan);
	param->plan = list_pl(param->map, param->data, param->plan, param->iso);
	listdel(&(param->map));
	mlx_key_hook(param->data.win_ptr, key_control, param);
	mlx_loop(param->data.mlx_ptr);
	return (0);
}

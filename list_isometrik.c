/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_isometrik.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstepany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 20:22:29 by lstepany          #+#    #+#             */
/*   Updated: 2020/10/27 21:14:30 by lstepany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "fdf.h"

int		x_i(t_data data)
{
	int zoom;

	zoom = 15;
	return ((2 * data.x - 2 * data.y) * zoom + 400);
}

int		y_i(t_list *map, t_data data)
{
	int *arr;
	int	zoom;

	zoom = 15;
	arr = (int *)map->content;
	return ((data.x + data.y - arr[data.x] * 2) * zoom + 300);
}

t_iso	*node(int x, int y, size_t content_size)
{
	t_iso *iso;

	while (!(iso = (t_iso *)malloc(sizeof(t_iso))))
	{
		ft_putstr("failed to allocate mamory");
		return (NULL);
	}
	iso->x = x;
	iso->y = y;
	iso->content_size = content_size;
	iso->next = NULL;
	return (iso);
}

t_iso	*list_isometrik(t_list *m, t_data data, t_iso *iso, t_list *temp)
{
	t_iso	*temp_iso;
	t_iso	*curr_node;

	temp = m;
	data.y = 0;
	while (m)
	{
		data.x = 0;
		while (data.x < m->content_size)
		{
			curr_node = node(x_i(data), y_i(m, data), m->content_size);
			if (data.x == 0 && data.y == 0)
			{
				temp_iso = curr_node;
				iso = temp_iso;
			}
			else
			{
				temp_iso->next = curr_node;
				temp_iso = curr_node;
			}
			data.x++;
		}
		data.y++;
		m = m->next;
	}
	//listdel(temp);
	return (iso);
}

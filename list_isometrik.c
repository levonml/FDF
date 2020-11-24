/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_isometrik.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstepany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 20:22:29 by lstepany          #+#    #+#             */
/*   Updated: 2020/11/24 20:16:19 by lstepany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fdf.h"

int		x_i(t_data data)
{
	return ((data.x - data.y) * ZOOM + 800);
}

int		y_i(t_list *map, t_data data)
{
	int *arr;

	arr = (int *)map->content;
	return ((data.x / 2 + (data.y - arr[(int)data.x] * Z) / 2) * ZOOM + 300);
}

t_iso	*node(int x, int y, size_t content_size)
{
	t_iso *iso;

	while (!(iso = (t_iso *)malloc(sizeof(*iso))))
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

t_iso	*list_is(t_list *temp, t_data d, t_iso *iso, t_iso *temp_iso)
{
	t_iso	*curr;

	d.y = 0;
	while (temp)
	{
		d.x = 0;
		while (d.x < temp->content_size)
		{
			curr = node(x_i(d), y_i(temp, d), (temp->content_size - d.x - 1));
			if (d.x == 0 && d.y == 0)
			{
				temp_iso = curr;
				iso = curr;
			}
			else
			{
				temp_iso->next = curr;
				temp_iso = curr;
			}
			d.x++;
		}
		d.y++;
		temp = temp->next;
	}
	return (iso);
}

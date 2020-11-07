/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_plan.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstepany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 20:59:17 by lstepany          #+#    #+#             */
/*   Updated: 2020/11/03 12:27:11 by lstepany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fdf.h"

int		x_p(t_data data)
{
	return (data.x * ZOOM + 200);
}

int		y_p(t_list *map, t_data data)
{
	int		*n;

	n = (int *)map->content;
	return (data.y * ZOOM + 250);
}

t_iso	*list_pl(t_list *temp, t_data data, t_iso *plan, t_iso *temp_plan)
{
	t_iso	*curr_node;

	data.y = 0;
	while (temp)
	{
		data.x = 0;
		while (data.x < temp->content_size)
		{
		  curr_node = node(x_p(data), y_p(temp, data), (temp->content_size - data.x - 1));
			if (data.x == 0 && data.y == 0)
			{
				temp_plan = curr_node;
				plan = temp_plan;
			}
			else
			{
				temp_plan->next = curr_node;
				temp_plan = curr_node;
			}
			data.x++;
		}
		data.y++;
		temp = temp->next;
	}
	return (plan);
}

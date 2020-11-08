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

t_iso	*list_pl(t_list *temp, t_data d, t_iso *plan, t_iso *temp_plan)
{
	t_iso	*curr;

	d.y = 0;
	while (temp)
	{
		d.x = 0;
		while (d.x < temp->content_size)
		{
			curr = node(x_p(d), y_p(temp, d), (temp->content_size - d.x - 1));
			if (d.x == 0 && d.y == 0)
			{
				temp_plan = curr;
				plan = temp_plan;
			}
			else
			{
				temp_plan->next = curr;
				temp_plan = curr;
			}
			d.x++;
		}
		d.y++;
		temp = temp->next;
	}
	return (plan);
}

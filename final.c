/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstepany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 19:50:21 by lstepany          #+#    #+#             */
/*   Updated: 2020/10/27 22:00:17 by lstepany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	final(t_iso *abs, t_iso *ord, t_data data)
{
	while (ord)
	{
		data.count = 1;
		while (data.count < abs->content_size)
		{
			drow_line(abs->x, abs->y, abs->next->x, abs->next->y, data);
			drow_line(abs->x, abs->y, ord->x, ord->y, data);
			abs = abs->next;
			ord = ord->next;
			data.count++;
		}
		drow_line(abs->x, abs->y, ord->x, ord->y, data);
		abs = abs->next;
		ord = ord->next;
	}
	data.count = 1;
	while (data.count < abs->content_size)
	{
		drow_line(abs->x, abs->y, abs->next->x, abs->next->y, data);
		abs = abs->next;
		data.count++;
	}
}

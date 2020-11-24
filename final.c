/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstepany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 19:50:21 by lstepany          #+#    #+#             */
/*   Updated: 2020/11/24 20:13:12 by lstepany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	drow_horizontal(t_iso *abs, t_data data)
{
	if (abs && !abs->next)
		drow_line(*abs, *abs, data);
	while (abs->next)
	{
		if (abs->content_size > 0)
			drow_line(*abs, *abs->next, data);
		abs = abs->next;
	}
}

void	drow_vertical(t_iso *abs, t_iso *ord, t_data data)
{
	t_iso *abs_temp;
	t_iso *ord_temp;

	while (ord)
	{
		abs_temp = abs;
		ord_temp = ord;
		while (abs_temp->content_size > 0 && ord_temp->content_size > 0)
		{
			drow_line(*abs_temp, *ord_temp, data);
			abs_temp = abs_temp->next;
			ord_temp = ord_temp->next;
		}
		drow_line(*abs_temp, *ord_temp, data);
		abs = next_row(abs);
		ord = next_row(ord);
	}
}

void	final(t_iso *abs, t_iso *ord, t_data data)
{
	drow_horizontal(abs, data);
	drow_vertical(abs, ord, data);
}

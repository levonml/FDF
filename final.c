/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstepany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 19:50:21 by lstepany          #+#    #+#             */
/*   Updated: 2020/11/03 12:30:15 by lstepany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	final(t_iso *abs1, t_iso *ord, t_data data)
{
	t_iso *abs;

	abs = abs1;
	while (ord)
	{
		data.count = 1;
		while (data.count < abs->content_size)
		{
			drow_line(*abs, *abs->next, data);
			drow_line(*abs, *ord, data);
			abs = abs->next;
			ord = ord->next;
			data.count++;
		}
		drow_line(*abs, *ord, data);
		abs = abs->next;
		ord = ord->next;
	}
	data.count = 1;
	while (data.count < abs->content_size)
	{
		drow_line(*abs, *abs->next, data);
		abs = abs->next;
		data.count++;
	}
}

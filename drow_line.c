/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drow_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstepany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 21:24:47 by lstepany          #+#    #+#             */
/*   Updated: 2020/11/03 12:37:36 by lstepany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_abs(float a)
{
	if (a < 0)
		return (-a);
	return (a);
}

void	drow_low(t_iso m1, t_iso m2, t_data data)
{
	float dx;
	float dy;
	float p;

	dx = m2.x - m1.x;
	dy = m2.y - m1.y;
	data.step = 1;
	if (dy < 0)
	{
		data.step = -1;
		dy = -dy;
	}
	p = 2 * dy - dx;
	while (m1.x <= m2.x)
	{
		mlx_pixel_put(data.mlx_ptr, data.win_ptr, m1.x, m1.y, COLOR);
		m1.x++;
		if (p < 0)
			p = p + 2 * dy;
		else
		{
			p = p + 2 * dy - 2 * dx;
			m1.y = m1.y + data.step;
		}
	}
}

void	drow_high(t_iso m1, t_iso m2, t_data data)
{
	float	dx;
	float	dy;
	float	p;

	dx = m2.x - m1.x;
	dy = m2.y - m1.y;
	data.step = 1;
	if (dx < 0)
	{
		data.step = -1;
		dx = -dx;
	}
	p = 2 * dx - dy;
	while (m1.y <= m2.y)
	{
		mlx_pixel_put(data.mlx_ptr, data.win_ptr, m1.x, m1.y, COLOR);
		m1.y++;
		if (p < 0)
			p = p + 2 * dx;
		else
		{
			p = p + 2 * dx - 2 * dy;
			m1.x = m1.x + data.step;
		}
	}
}

void	drow_line(t_iso m1, t_iso m2, t_data data)
{
	if (ft_abs(m2.y - m1.y) < ft_abs(m2.x - m1.x))
	{
		if (m1.x > m2.x)
			drow_low(m2, m1, data);
		else
			drow_low(m1, m2, data);
	}
	else
	{
		if (m1.y > m2.y)
			drow_high(m2, m1, data);
		else
			drow_high(m1, m2, data);
	}
}

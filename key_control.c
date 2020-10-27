/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstepany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 21:19:53 by lstepany          #+#    #+#             */
/*   Updated: 2020/10/27 21:23:11 by lstepany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>

int	key_control(int key, void *param)
{
	t_param	*temp;
	t_param *temp1;

	temp = (t_param *)param;
	drow_grid1(temp);
	if (key == 53)
		exit(0);
	if (key == 50)
	{
		temp1 = temp;
		drow_grid(temp1);
	}
	return (0);
}

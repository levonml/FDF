/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstepany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 21:19:53 by lstepany          #+#    #+#             */
/*   Updated: 2020/11/24 20:24:17 by lstepany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>

int	key_control(int key, void *param)
{
	t_param	*temp;

	temp = (t_param *)param;
	if (key == 124)
		drow_iso(temp);
	if (key == 53)
		exit(0);
	if (key == 123)
		drow_plan(temp);
	return (0);
}

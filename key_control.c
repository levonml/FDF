/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstepany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 21:19:53 by lstepany          #+#    #+#             */
/*   Updated: 2020/11/03 12:40:24 by lstepany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>

int	key_control(int key, void *param)
{
	t_param	*temp;

	temp = (t_param *)param;
	drow_iso(temp);
	if (key == 65307)
		exit(0);
	if (key == 65363)
		drow_plan(temp);
	return (0);
}

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
	temp1 = temp;
	drow_iso(temp);
	if (key == 65307)
		exit(0);
	if (key == 65363)
	{
	  drow_plan(temp);
	}
	//listdel(temp1->map, temp1->iso);
	//free(temp);
	return (0);
}

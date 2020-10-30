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

#include <stdlib.h>
void    iso_listdel(t_iso *head)                                                                                                                 
{                                                                                                                                                  
        t_iso  *temp;                                                                                                                             
                                                                                                                                                   
                                                                                                                                                   
        while (head)                                                                                                                               
        {                                                                                                                                          
                temp = head;                                                                                                                       
                head = head->next;                                                                                                                                free(temp);                                                                                                                        
                temp = NULL;                                                                                                                       
	}
}

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
	//		iso_listdel(abs1);
}

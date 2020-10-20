/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstepany <lstepany@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 09:26:24 by lstepany          #+#    #+#             */
/*   Updated: 2020/08/07 13:39:02 by lstepany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include "fdf.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/errno.h>
int	*convert(char *str, int *count)
{
  int *arr;
  char **split;

  split = ft_strsplit(str, ' ');
  *count = 0;
  while (split[*count])
    (*count)++;
  arr = (int *)malloc(sizeof(int) * (*count));
  *count = 0;
  while (split[*count])
    {
      arr[*count] = ft_atoi(split[*count]);
      (*count)++;
    }
  return (arr);
  
}

t_list	*get_map(int fd, t_data data, t_list *map)
{
  t_list      	*temp;
  t_list       	*curr_node;
  char		*line;
  int		*line_int;

  data.count = 0;
  while (get_next_line(fd, &line) == 1)
    {
      line_int = convert(line, &data.x);
      curr_node = ft_lstnew(line_int, data.x);
      if (data.count == 0)
	{
        temp = curr_node;
	map = temp;
	}
      else
	{
	  temp->next = curr_node;
	  temp = curr_node;
	}
          free(line);
      data.count++;
    }
  temp = map;
  return (map);
}

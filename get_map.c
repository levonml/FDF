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

t_list	*get_map(int fd)
{
  size_t	count;
  char		*line;
  t_list        *map;
  t_list      	*temp;
  t_list       	*curr_node;
  int		*line_int;
  int		*n;
  int		len;

  count = 0;
  while (get_next_line(fd, &line) == 1)
    {
      line_int = convert(line, &len);
      curr_node = ft_lstnew(line_int, len);
      if (count == 0)
	{
        temp = curr_node;
	map = temp;
	}
      else
	{
	  temp->next = curr_node;
	  temp = curr_node;
	}
      count++;
    }
  temp = map;
  free(line);
  return (map);
}

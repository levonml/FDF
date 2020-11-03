/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstepany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 20:04:48 by lstepany          #+#    #+#             */
/*   Updated: 2020/10/27 20:36:01 by lstepany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "fdf.h"
#include <stdlib.h>

#include<stdio.h>

int		*convert(char *str, size_t *count)
{
	int    	*arr;
	char	**split;

	if (!(split = ft_strsplit(str, ' ')))
		return (NULL);
	*count = 0;
	while (split[*count])
		(*count)++;
	if (!(arr = (int *)malloc(sizeof(int) * (*count))))
		return (NULL);
	*count = 0;
	while (split[*count])
	{
		arr[*count] = ft_atoi(split[*count]);
		free(split[*count]);
		//split[*count] = NULL;
		(*count)++;
	}
	free(split);
	return (arr);
}

t_list	*get_map(int fd, t_data data, t_list *map, t_list *temp)
{
	t_list	*curr_node;
	char	*line;
	int    	*line_int;
	
	data.count = 0;
	while (get_next_line(fd, &line) == 1)
	{
		if (!(line_int = convert(line, &data.x)) \
	|| !(curr_node = ft_lstnew(line_int, data.x)))
			return (NULL);
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
		line = NULL;
		data.count++;
	}
	return (map);
}

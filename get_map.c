/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstepany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 20:04:48 by lstepany          #+#    #+#             */
/*   Updated: 2020/11/24 16:40:26 by lstepany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "fdf.h"
#include <stdlib.h>

int		validate_arr(char *arr)
{
	int			i;

	i = 0;
	if ((arr[i] == '-' && (arr[i + 1] > '0' && arr[i + 1] <= '9'))	\
	|| (arr[i] >= '0' && arr[i] <= '9'))
		i++;
	else
	{
		ft_putstr("invalid map");
		exit(0);
	}
	return (i);
}

int		*convert(char *str, float *count)
{
	char		**split;
	int			*arr;

	if (!(split = ft_strsplit(str, ' ')))
		return (NULL);
	*count = 0;
	while (split[(int)*count])
		(*count)++;
	if (!(arr = (int *)malloc(sizeof(int) * (*count))))
		return (NULL);
	*count = 0;
	while (split[(int)*count])
	{
		validate_arr(split[(int)*count]);
		arr[(int)*count] = ft_atoi(split[(int)*count]);
		if (abs(arr[(int)*count]) > 30000)
		{
			ft_putstr("invalid map: 'z' value is out of scope\n");
			exit(0);
		}
		free(split[(int)*count]);
		(*count)++;
	}
	free(split);
	return (arr);
}

t_list	*get_map(int fd, t_data data, t_list *map, t_list *temp)
{
	t_list		*curr_node;

	data.count = 0;
	while (get_next_line(fd, &data.line) == 1)
	{
		if (!(data.line_int = convert(data.line, &data.x))		\
		|| !(curr_node = ft_lstnew(data.line_int, data.x)))
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
		free(data.line);
		data.count++;
	}
	if (get_next_line(fd, &data.line) == -1)
		exit(0);
	return (map);
}

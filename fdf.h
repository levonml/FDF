/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstepany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 12:40:51 by lstepany          #+#    #+#             */
/*   Updated: 2020/11/03 12:45:06 by lstepany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define COLOR 0xff0000
# define Z 1
# define ZOOM 15
# include "libft/libft.h"
# include "mlx.h"

typedef struct	s_data
{
	void			*mlx_ptr;
	void			*win_ptr;
	int				step;
	size_t			count;
	float			x;
	float			y;
  int *line_int;
  char *line;
}				t_data;
typedef struct	s_iso
{
	float				x;
	float				y;
	size_t			content_size;
	struct s_iso	*next;
}				t_iso;
typedef struct	s_param
{
	int				fd;
	t_data			data;
	t_list			*map;
	t_iso			*iso;
	t_iso			*plan;
	t_list			*map1;
}				t_param;
t_iso			*next_row(t_iso *ord);
void			final(t_iso *abs, t_iso *ord, t_data data);
void			drow_iso(t_param *param);
void			drow_plan(t_param *param);
int			ft_abs(float a);
int				key_control(int key, void *param);
t_list			*get_map(int fd, t_data data, t_list *temp, t_list *temp1);
void			drow_line(t_iso m1, t_iso m2, t_data data);
t_iso			*list_is(t_list *t, t_data data, t_iso *iso, t_iso *iso1);
t_iso			*list_pl(t_list *t, t_data data, t_iso *plan, t_iso *plan1);
void			listdel(t_list **list);
t_iso			*node(int x, int y, size_t content_size);
#endif

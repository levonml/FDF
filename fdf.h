#ifndef FDF_H
#define FDF_H
#include "libft/libft.h"
#include "mlx.h"


typedef struct	s_data
{
  void 	*mlx_ptr;
  void	*win_ptr;
  int	step;
  size_t	count;
  size_t	x;
  size_t	y;
}		t_data;
typedef struct  s_iso
{
  int           x;
  int           y;
  int		z;
  size_t	content_size;
  struct s_iso  *next;
}               t_iso;
typedef struct	s_param
{
  int		fd;
  t_data	data;
  t_list	*map;
  t_iso		*iso;
  t_iso		*plan;
  t_list	*map1;
}		t_param;
void    final(t_iso *abs, t_iso *ord, t_data data);
void    drow_grid(t_param *param);
void    drow_grid1(t_param *param);
int		key_control(int key, void *param);
t_list		*get_map(int fd, t_data data, t_list *temp, t_list *temp1);
void		drow_line(int x1, int y1, int x2, int y2, t_data data);
t_iso		*list_isometrik(t_list *temp, t_data data, t_iso *iso, t_list *map);
t_iso		*list_plan(t_list *temp, t_data data, t_iso *plan, t_list *map);
void listdel(t_list *list);
t_iso *node(int x, int y,  size_t content_size);
#endif

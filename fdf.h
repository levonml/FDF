#ifndef FDF_H
#define FDF_H
#include "libft/libft.h"
#include "mlx.h"
typedef struct	s_data
{
  void 	*mlx_ptr;
  void	*win_ptr;
  int	step;
  int	p;
  int	count;
  int x;
  int y;
}		t_data;
typedef struct	s_iso
{
  int		x;
  int		y;
  struct s_iso	*next;
}		t_iso;
t_list		*get_map(int fd, t_data data, t_list *temp);
void		drow_line(int x1, int y1, int x2, int y2, t_data data);
t_iso		*create_list(t_list *temp, t_data data);
#endif

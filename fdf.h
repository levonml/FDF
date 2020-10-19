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
  int	i;
}		t_data;

t_list		*get_map(int fd);
void		drow_line(int x1, int y1, int x2, int y2, t_data data);
#endif

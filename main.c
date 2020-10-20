#include <unistd.h>
#include <stdlib.h>
#include "fdf.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

t_iso	*next_row(t_list *temp, t_iso *ord)
{
  while (temp->content_size)
    {
      ord = ord->next;
      temp->content_size--;
    }
  return(ord);
}
void	final(t_iso *iso, t_iso *abs, t_iso *ord, t_list *temp, t_data data)
{
  while((temp->next))
    {
      temp = temp->next;
      data.count = 1;
      while(data.count < 19)
        {
          drow_line(abs->x, abs->y, abs->next->x, abs->next->y, data);
          drow_line(abs->x, abs->y, ord->x, ord->y, data);
          abs = abs->next;
          ord = ord->next;
          data.count++;
        }
      drow_line(abs->x, abs->y, ord->x, ord->y, data);
      abs = abs->next;
      ord = ord->next;
    }
  data.count = 1;
  while(data.count < temp->content_size)
    {
      drow_line(abs->x, abs->y, abs->next->x, abs->next->y, data);
      abs = abs->next;
      data.count++;
      }  
}
void    drow_grid(t_list *temp, t_data data)
{
  t_iso		*iso;
  t_iso		*abs;
  t_iso		*ord;

  iso = create_list(temp, data);
  abs = iso;
  ord = next_row(temp, iso);
  final(iso, abs, ord, temp, data);
}
int main(int argc, char **argv)
{
  t_data	data;
  int           fd;
  t_list        *map;
  int		*n;
  t_list	*temp;
  
  if (argc == 1 )
    fd = 0;
  else
    {
      fd = open(argv[1], O_RDONLY);
      if (fd == -1)
	printf("error N %d", errno);
    }
  map = get_map(fd);
  close(fd);
  data.mlx_ptr = mlx_init();
  data.win_ptr = mlx_new_window(data.mlx_ptr, 700, 700, "mlx 42");
  drow_grid(map, data);
  
  mlx_loop(data.mlx_ptr);
  return (0);
}

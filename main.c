#include <unistd.h>
#include <stdlib.h>
#include "fdf.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

int x_iso(int x, int y)
{
  return(x - y);
}
int y_iso(t_list *map, int count, int x, int y)
{
  int *n;
  
  n = (int *)map->content; 
  return(x/2 + y/2 - 2*n[count]);
  
  }
void    drow_grid(t_list *map, t_data data)
{
  t_list	*temp;
  int		count;
  int x1;
  int y1;
  int x2;
  int y2;
  int step;
  int i;
  int w;

  temp = map;
  y1 = 50;
  y2 = 50;
  w = 20;
  while (temp)
    {
      step = 20;
      x1 = 370;
      x2 = 370 + step;
      count = 0;
      while (count < 19)
	{
	  if(count == 0)
	    {
	      x1 = x_iso(370, y1);
	      y1 = y_iso(temp, count, 370, y1);
	    }
	  count++;
	  drow_line(x1, y1, x_iso(x2, y2), y_iso(temp, count, x2, y2), data);
	  x1 = x_iso(x2, y2);
	  y1 = y_iso(temp, count, x2, y2);
	  x2 = x2 + step;
	}
      y1 = 50 + w;
      y2 = 50 + w;
      w += 20;
      temp = temp->next;
    }
  temp = map;
  x1 = 370;
  x2 = 370;
  w = 0;
  count = 0;
     while (count < 19)
    {
      step = 20;
      y1 = 30;
      y2 = 30 + step;
      i = 0;
      //count++;
      while (temp)
        {
	  if(i == 0)
	    {
	      x1 = x_iso(x1, y1);
              y1 = y_iso(temp, count, 370 + w, y1);
	    }
	  i++;
          drow_line(x1, y1, x_iso(x2, y2), y_iso(temp, count, x2, y2), data);
	  x1 = x_iso(x2, y2);
	  y1 = y_iso(temp, count, x2, y2);
          y2 += step;
	  temp = temp->next;
        }
            count++;
      temp = map;
      w += 20;
      x1 = w + 370;
      x2 = w + 370;
      }
    }
int main(int argc, char **argv)
{
  t_data	data;
  int           fd;
  t_list        *map;
  int		*n;
  int		i;
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

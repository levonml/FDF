#include <unistd.h>
#include <stdlib.h>
#include "fdf.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int abs(int a)
{
  if (a < 0)
    return (-a);
  return (a);
}
void drow_low(int x1, int y1, int x2, int y2, t_data data)
  {
    int dx;
    int dy;
    
    dx = x2 - x1;
    dy = y2 - y1;
    data.step = 1;
    if (dy < 0)
      {
	data.step = -1;
	dy = -dy;
      }
    data.p = 2 * dy - dx;
    while (x1 <= x2)
      {

		mlx_pixel_put(data.mlx_ptr, data.win_ptr, x1, y1, 0xff0000);
		x1++;
		if (data.p < 0)
			  data.p = data.p + 2 * dy;
		  else
		  {
			  data.p = data.p + 2 * dy - 2 * dx;
			  y1 = y1 + data.step;
		  }
      }
  }
void drow_high(int x1, int y1, int x2, int y2, t_data data)
  {
    int dx;
    int dy;

    dx = x2 - x1;
    dy = y2 - y1;
    data.step = 1;
    if (dx < 0)
      {
	data.step = -1;
	dx = -dx;
      }
    data.p = 2 * dx - dy;
    while (y1 <= y2)
      {
	mlx_pixel_put(data.mlx_ptr, data.win_ptr, x1, y1, 0xff0000);
	y1++;
	if (data.p < 0)
	  data.p = data.p + 2 * dx;
	else
	  {
	    data.p = data.p + 2 * dx - 2 * dy;
	    x1 = x1 + data.step;
	  }
      }
  }
void	drow_line(int x1, int y1, int x2, int y2, t_data data)
{
  if (abs(y2 - y1) < abs(x2 - x1))
            {
              if (x1 > x2)
                drow_low(x2, y2, x1, y1, data);
              else
                drow_low(x1, y1, x2, y2, data);
            }
          else
            {
              if (y1 > y2)
                drow_high(x2, y2, x1, y1, data);
              else
                drow_high(x1, y1, x2, y2, data);
            }
}

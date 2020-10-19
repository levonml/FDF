#include "mlx.h"
#include <unistd.h>
#include <stdlib.h>
#include "fdf.h"
#include <stdio.h>

void print_map()
{
  int i;
  int j;
  int map[4][5];

  i = 0;
  j = 0;
  while (i < 4)
    {
      j = 0;
      while (j < 5)
        {
          map[i][j] = 0;
           printf("%d ", map[i][j]);
          j++;
        }
      printf("\n");
      i++;
    }
}
int abs(int a)
{
  if (a < 0)
    return (-a);
  return (a);
}
void drow_low(int x1, int y1, int x2, int y2, void *mlx_ptr, void *win_ptr)
  {
    int dx;
    int dy;
    int p;
    int step;
    int x;
    int y;
    
    dx = x2 - x1;
    dy = y2 - y1;
    step = 1;
    if (dy < 0)
      {
	step = -1;
	dy = -dy;
      }
    p = 2 * dy - dx;
    x = x1;
    y = y1;
    {
      while (x <= x2)
        {
          mlx_pixel_put(mlx_ptr, win_ptr, x, y, 0xff0000);
          x++;
          if (p < 0)
            p = p + 2 * dy;
          else
            {
              p = p + 2 * dy - 2 * dx;
              y = y + step;
            }
        }
    }
  }
void drow_high(int x1, int y1, int x2, int y2, void *mlx_ptr, void *win_ptr)
  {
    int dx;
    int dy;
    int x;
    int y;
    int p;
    int step;
    
    dx = x2 - x1;
    dy = y2 - y1;
    step = 1;
    if (dx < 0)
      {
	step = -1;
	dx = -dx;
      }
    p = 2 * dx - dy;
    x = x1;
    y = y1;
    while (y <= y2)
      {
	mlx_pixel_put(mlx_ptr, win_ptr, x, y, 0xff0000);
	y++;
	if (p < 0)
	  p = p + 2 * dx;
	else
	  {
	    p = p + 2 * dx - 2 * dy;
	    x = x + step;
	  }
      }

  }
void    drow_grid(void *mlx_ptr, void *win_ptr)
{
  int x1;
  int y1;
  int x2;
  int y2;
  int count;
  /*  int i;
  int j;
  int map[4][5];

  i = 0;
  j = 0;
  while (i <= 4)
    {
      j = 0;
      while (j <= 5)
	{
	  map[i][j] = 0;
	   printf("%d ", map[i][j]);
	  j++;
	}
      printf("\n");
      i++;
    }*/
  x1 = 300;
  y1 = 300;
  x2 = 300;
  y2 = 1000;
  count = 0;
  while (count <= 100)
    {
      if (abs(y2 - y1) < abs(x2 - x1))
	{
	  if (x1 > x2)
	    drow_low(x2, y2, x1, y1, mlx_ptr, win_ptr);
	  else
	    drow_low(x1, y1, x2, y2, mlx_ptr, win_ptr);
	}
      else
	{
	  if (y1 > y2)
	    drow_high(x2, y2, x1, y1, mlx_ptr, win_ptr);
	  else
	    drow_high(x1, y1, x2, y2, mlx_ptr, win_ptr);
	}
      count++;
      if (y2 >= 300)
	x2 += 20;
      else if (y2 < 300)
	(x2 -= 20);
      if (x2 >= 300)
	y2 -= 20;
      else if (x2 < 3000)
	y2 += 20;
    }
}
int main()
{
  void *mlx_ptr;
  void *win_ptr;
  print_map();
  mlx_ptr = mlx_init();
  win_ptr = mlx_new_window(mlx_ptr, 700, 700, "mlx 42");
  drow_grid(mlx_ptr, win_ptr);
  mlx_loop(mlx_ptr);
  return (0);
}

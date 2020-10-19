#include <mlx.h>
#include <unistd.h>
#include <stdlib.h>
#include "fdf.h"

t_list *create_list()
{
  t_list *list;
  t_list *temp;
  int x1;
  int y1;
  int x2;
  int y2;
  int p;
  
  x1 = 300;
  y1 = 300;
  x2 = 400;
  y2 = 300;
  p = 2*(y2 - y1) - (x2 - x1);
  list = NULL;
  if(!(list = (t_list *)malloc(sizeof(t_list))))
    return (NULL);
  temp = list;
       while (x1 <= x2)
	{
	  temp->x = x1;
	  temp->y = y1;
	  x1++;
	  if (p < 0)
	     p = p + 2 * (y2 - y1);
	  else
	    {
	      p = p + 2 * (y2 - y1) - 2 * (x2 - x1);
	      y1++;
	    }
	  temp->next = (t_list *)malloc(sizeof(t_list));
	  temp = temp->next;
	}
  temp = NULL;
  return (list);
}
int main()
{
  t_list *list;
  t_list *temp;
  void *mlx_ptr;
  void *win_ptr;
  
  list = create_list();
  temp = list;
  mlx_ptr = mlx_init();
  win_ptr = mlx_new_window(mlx_ptr, 500, 500, "mlx 42");
  while (temp)
    {
      mlx_pixel_put(mlx_ptr, win_ptr, temp->x, temp->y, 0xff0000);
      temp = temp->next;
    }
  //  mlx_string_put(mlx_ptr, win_ptr, 50, 50, 0x0dfff0, "#ArtsakhStrong");
  // mlx_key_hook(win_ptr, deal_key, (void *)0);
  mlx_loop(mlx_ptr);
  return (0);
}

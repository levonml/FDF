#include "mlx.h"
#include <unistd.h>
#include <stdlib.h>
#include "fdf.h"
/*void ft_putchar(char c)
{
  write(1, &c, 1);
}
int deal_key(int key, void *param)
{
  key = 0x0020;
  ft_putchar('X');
  return(0);
  }*/
t_list *create_list()
{
  int x_count;
  int y_count;
  t_list *list;
  t_list *temp;
  int a;
  int b;
  list = NULL;
  if(!(list = (t_list *)malloc(sizeof(t_list))))
    return (NULL);
  temp = list;
  b = 1;
  // temp->x = 10;
  //temp->y = 10;
  //temp->next = NULL;
  y_count = 1;
  while (y_count <= 200)
    {
      x_count = 1;
      b = b + 1;
      a = 1;
      while (x_count <= 400)
	{
	  temp->x = a;
	  temp->y = b;
	  a = a + 1;
	  temp->next = (t_list *)malloc(sizeof(t_list));
	  temp = temp->next;
	  x_count++;
	}
      y_count++;
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
      mlx_pixel_put(mlx_ptr, win_ptr, temp->x, temp->y, 0xffd5b6);
      temp = temp->next;
    }
  //  mlx_string_put(mlx_ptr, win_ptr, 50, 50, 0x0dfff0, "#ArtsakhStrong");
  // mlx_key_hook(win_ptr, deal_key, (void *)0);
  mlx_loop(mlx_ptr);
  return (0);
}

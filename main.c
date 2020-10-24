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
  int i;
  i = 0;
  while (i < temp->content_size)
    {
      ord = ord->next;
      i++;
    }
  return(ord);
}

void	final(t_iso *a, t_iso *o, t_list *map, t_data data)
{
  t_iso *abs;
  t_iso *ord;
  t_list *temp;
  abs = a;
  ord = o;
  temp = map;
  while(temp->next)
    {
      temp = temp->next;
      data.count = 1;
      while (data.count < temp->content_size)
        {
	  drow_line(abs->x, abs->y, abs->next->x, abs->next->y, data);
	  drow_line(abs->x, abs->y, ord->x, ord->y, data);
	  printf("abs->x = %d\n", abs->x);
	  printf("abs->y = %d\n", abs->y);
	  printf("ord->x = %d\n", ord->x);
	  printf("ord->y = %d\n", ord->y);
	  abs = abs->next;
	  ord = ord->next;
	  data.count++;
	}
      drow_line(abs->x, abs->y, ord->x, ord->y, data);
      abs = abs->next;
      ord = ord->next;
    }
  data.count = 1;
  while (data.count < temp->content_size)
    {
      drow_line(abs->x, abs->y, abs->next->x, abs->next->y, data);
      abs = abs->next;
      data.count++;
    }
}

void	drow_grid(t_param *param)
{
  t_iso		*abs;
  t_iso		*ord;

  mlx_clear_window(param->data.mlx_ptr, param->data.win_ptr);
  abs = param->iso ;
  ord = next_row(param->map, param->iso);
  final(abs, ord, param->map, param->data);
}
void    drow_grid1(t_param *param)
{
  t_iso         *abs;
  t_iso         *ord;
  mlx_clear_window(param->data.mlx_ptr, param->data.win_ptr);
  abs = param->plan ;
  ord = next_row(param->map, param->plan);
  final(abs, ord, param->map, param->data);
}

int isometrik2(int key, void *param)
{
  	t_data	data;
  	t_param	*temp;
	t_param *temp1;
	temp = (t_param *)param;
	drow_grid1(temp);
        if (key == 65307)
          exit(0);
        if (key == 49)
	  {
	    temp1 = temp;
	  drow_grid1(temp1);
	  }
	if(key == 50)
	  {
	    temp1 = temp;
	    drow_grid(temp1);
	  }
	//	drow_grid(temp);
        return(0);
	}

int		exit_prog(int key, void *param)
{
	if (key == 65307)
		exit(0);
	return (0);
	}
int	main(int argc, char **argv)
{
  int           fd;
  t_param	*param;
  t_list *map;
  t_data data;
  
  if (argc == 1)
  {
	  fd = 0;
	  printf("argument is missing\nusage: ./fdf file_name\n");
	  return(0);
  }
  else
    {
      fd = open(argv[1], O_RDONLY);
      if (fd == -1)
	  {
	    printf ("file opening error");
	    return(0);
	  }
    }
  param = malloc(sizeof(param));
  map = get_map(fd, data, map);
  close(fd);
  param->map = map;
  param->data.mlx_ptr = mlx_init();
  param->data.win_ptr = mlx_new_window(param->data.mlx_ptr, 1000, 1000, "fdf pateh-unpateh");
  param->iso = create_list(param->map, param->data);
  param->plan = create_plan(param->map, param->data);
  mlx_key_hook(param->data.win_ptr, isometrik2, param);
  mlx_loop(param->data.mlx_ptr);
 
  return (0);
}

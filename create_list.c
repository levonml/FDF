#include <stdlib.h>
#include <stdio.h>
#include "fdf.h"
int isometrik(int key, void *param)
{
	int ret;
	ret = 1;
	if (key == 53)
		exit(0);
	else
		if (key == 49)
			//ft_putstr("iso works!");
			ret = 0;
		else
			if(key == 50)
				ret = 1;
	return(ret);
}
int x_iso(int x, int y, t_data data)
{
	int i;
	int p;
	mlx_key_hook(data.win_ptr, isometrik, (void *)0);
	i = isometrik(p, 0);
	if (i == 1)
		return((2*x - 2*y) * 18 + 400);
	else
	{
		printf("isometrik = %d\n", i);
		return(20*x + 400);
	}
}

int y_iso(t_list *map, int count, int x, int y, t_data data)
{
  int *n;
  int i;
  int p;
  mlx_key_hook(data.win_ptr, isometrik, (void *)0);
  i = isometrik(p,0);
  n = (int *)map->content; 
  if(i == 1)
	  return((x + y - n[count]/8) *18 + 250);
  else
	  return (y * 20 + 250);
  
}

t_iso *create_node(int x, int y)
{
  t_iso *iso;

  while(!(iso = (t_iso *)malloc(sizeof(t_iso))))
    return(NULL);
  iso->x = x;
  iso->y = y;
  iso->next = NULL;
  return (iso);
}

t_iso *create_list(t_list *temp, t_data data)
{
  t_iso		*temp_iso;
  t_iso		*curr_node;
  t_iso		*iso;
  
//  isometrik((void *)0);
  data.y = 0;
  while (temp)
    {
      data.x = 0;
      while (data.x < temp->content_size)
	{
		curr_node = create_node(x_iso(data.x, data.y, data), y_iso(temp, data.x, data.x, data.y, data));
	  if (data.x == 0 && data.y == 0)
	    {
	      temp_iso = curr_node;
	      iso = temp_iso;
	    }
	  else
	    {
	      temp_iso->next = curr_node;
	      temp_iso = curr_node;
	    }
	  data.x++;
	}
      data.y++;
      temp = temp->next;
    }
  return(iso);
}

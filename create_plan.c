#include <stdlib.h>
#include <stdio.h>
#include "fdf.h"

int x_iso1(int x, int y, t_data data)
{
	  return(x * 15 + 400);
}

int y_iso1(t_list *map, int count, int x, int y, t_data data)
{
  int zoom;
  int *n;

  n = (int *)map->content;
  zoom = 250;
  return(y * 15 + zoom);
}

t_iso *create_node1(int x, int y)
{
  t_iso *iso;

  while(!(iso = (t_iso *)malloc(sizeof(t_iso))))
    return(NULL);
  iso->x = x;
  iso->y = y;
  iso->next = NULL;
  return (iso);
}

t_iso *create_plan(t_list *param, t_data data)
{
  t_iso		*temp_iso;
  t_iso		*curr_node;
  t_iso		*iso;
  t_list *temp;
  printf("parampampam");
  temp = param;
//  isometrik((void *)0);
  data.y = 0;
  while (temp)
    {
      data.x = 0;
      while (data.x < temp->content_size)
	{
		curr_node = create_node1(x_iso1(data.x, data.y, data), y_iso1(temp, data.x, data.x, data.y, data));
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

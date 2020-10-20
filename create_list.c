#include <stdlib.h>
#include "fdf.h"

int x_iso(int x, int y)
{
  return((2*x - 2*y) * 12 + 250);
}

int y_iso(t_list *map, int count, int x, int y)
{
  int *n;
  
  n = (int *)map->content; 
  return((x + y - n[count]/6) * 12 + 250);
  
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
  
  data.y = 0;
  while (temp)
    {
      data.x = 0;
      while (data.x < temp->content_size)
	{
	  curr_node = create_node(x_iso(data.x, data.y), y_iso(temp, data.x, data.x, data.y));
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

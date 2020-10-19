#include <stdio.h>
#include <stdlib.h>
void  print_map()
{
  int i;
  int j;
  int **map;
  //int map[4][5];                                                       

  map = (int **)malloc(sizeof(int *) * 5);
  j = 0;
  while (j < 5)
    {
      map[j] = malloc(sizeof(int) * 5);
      j++;
    }

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
int main()
{
  print_map();
  return(0);
}

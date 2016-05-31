/*
** main.c for main in /home/anzer_r/project/dicowesh/anzer_r/discowesh/core
** 
** Made by ANZER ryan
** Login   <anzer_r@etna-alternance.net>
** 
** Started on  Fri Apr 17 10:36:53 2015 ANZER ryan
** Last update Sat Apr 18 13:55:35 2015 ANZER ryan
*/
#include "core/header.h"

void* malloc(size_t size);
void free(void *ptr);

extern t_block *g_block;

void dump() {
  t_block *last;
  //int i;
  
  last = g_block;
  while (last)
    {
      my_putstr("-- block_dump: ");
      my_put_nbr(last->free);
      my_putstr(", size: ");
      my_put_nbr((int)last->size);
      my_putstr(", value: ");
      my_putstr(last->data);
      my_putstr(" --\n"); 
      
      last = last->next; 
    }
  my_putstr("===========\n");
}

void test(int max, char c)
{
  char *list;
  int i;
  
  list = malloc(sizeof(char) * (max + 1));
  if (list)
    {
      i = 0;
      while (i < max)
      {
	list[i] = c;
	i += 1;		
      }
      list[max] = '\0';
    }
}

int main()
{
  int i;
  t_block *last;
  int run;  
  
  run = 1;
  while (run) {
    i = 0;
    while (i < 10)
      {
	test(10 + i, 'a');
	i += 1;
      }
    
    i = 0; // Free half of avaible values
    last = g_block;  
    while (last)
      {
	if (i % 2 == 0 || i == 1)
	  free(last->data);
	i += 1;
	last = last->next; 
    }
    dump();
  }
  
  return (0);
}

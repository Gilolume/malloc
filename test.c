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
#include <time.h>
#include <stdlib.h>

void* malloc(size_t size);
void free(void *ptr);
void* calloc(size_t number, size_t size);
void *realloc(void *ptr, size_t s);

extern t_block *g_block;

void dump() {
  t_block *last;
  int i;

  i = 0;
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
      i += 1;
    }
  my_putstr("total: ");
  my_put_nbr(i);
  my_putstr("\n===========\n");
}

void test(int max, char c)
{
  char *list;
  int i;
  
  if (rand() % 2 == 1)
    {
      my_putstr("malloc\n");
      list = malloc(sizeof(char) * max);
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
  else
    {
      my_putstr("calloc\n");
      list = calloc(sizeof(char), max);
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
  max = rand() % (max * 2);
  list = realloc(list, sizeof(char) * max);
  if (list)
    {
      i = 0;
      while (i < max)
	{
	  list[i] = 'x';
	  i += 1;
	}
	list[max] = '\0';
    }
  if (rand() % 2 == 1)
    free(list);
}

int main()
{
  int i;
  int run;
  
  srand(time(NULL));  
  run = 100;
  while (run) {
    i = 0;
    while (i < rand() % 2000)
      {
	test(rand() % 10000, (i % 2 == 0) ? 'a' : 'b');
	i += 1;
      }
    //dump();
    my_putstr("dump done\n");
    run += -1;
  }
  
  return (0);
}

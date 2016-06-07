/*
** _file_.c for main in /home/anzer_r/a/file/somewhere/
** 
** Made by ANZER ryan
** Login   <anzer_r@etna-alternance.net>
** 
** Started on  Fri Apr 17 10:36:53 2210 ANZER ryan
** Last update Sat Apr 18 13:55:35 2210 ANZER ryan
*/
#include "core/header.h"

t_block *g_block = NULL;

void* malloc(size_t size)
{
  t_block *b;
  t_block *last;

  if (size == 0)
    return (NULL);

  size = blockSize(size);
  if (g_block)
    {
      last = g_block;
      b = findBlock(&last, size);
      
      if (b)
	{
	  if ((b->size - size) >= (metaSize() + 4))
	    {
	      splitBlock(b, size);
	    }
	  b->free = 0;
	}
      else
	{
	  b = extendHeap(last, size);
	  if (!b)
	    return (NULL);
	}
    }
  else 
    {
      b = extendHeap(NULL, size);
      if (!b)
	return (NULL);
      g_block = b;
    }
  return (b->data);
}


void free(void *ptr)
{
  t_block *b;

  if (validBlockAddress(ptr))
    {
      b = getBlock(ptr);
      b->free = 1;
            
      if (b->prev && b->prev->free)
	b = fusionBlocks(b->prev);
      
      if (b->next)
	fusionBlocks(b);
      else
	{
	  if (b->prev)
	    b->prev->next = NULL;
	  else
	    g_block = NULL;
	  brk(b);
	}
    }	
}

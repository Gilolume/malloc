/*
** action.c for action in /home/anzer_r/project/dicowesh/anzer_r/discowesh
** 
** Made by ANZER ryan
** Login   <anzer_r@etna-alternance.net>
** 
** Started on  Fri Apr 17 14:18:11 2015 ANZER ryan
** Last update Sat Apr 18 13:54:42 2015 ANZER ryan
*/
#include "header.h"

extern t_block *g_block;

int blockSize(int n)
{
	return ((((n - 1) >> 2) << 2) + 4);
}

int metaSize()
{
  return (40);
}

t_block* findBlock(t_block **chain, size_t size)
{
	t_block *b;
	
	b = *chain;
	while (b && !(b->free && b->size >= size))
  {
    b = b->next;
    if (b)
      *chain = b;
  }

	return (b);
}

t_block* extendHeap(t_block *chain, size_t size)
{
	t_block *b;

	b = sbrk(0);
	if (sbrk(metaSize() + size) == (void*) -1)
		return (NULL);
	
	b->size = size;
	b->next = NULL;
	b->prev = chain;
  b->ptr = b->data;
  b->free = 0;
	if (chain)
		chain->next = b;

	return (b);
}

void splitBlock(t_block *b, size_t size)
{
	t_block *new;

  new = (t_block *)(b->data + size);
  new->size = (size_t)((b->size - size) - metaSize());
  new->free = 1;
	new->next = b->next;
	new->prev = b;
  new->ptr = new->data;
  if (new->next)
	  new->next->prev = b;
 
  
  b->size = size;
	b->next = new;
}


t_block *getBlock(void *ptr)
{
  char *tmp;
  tmp = ptr;
  return (ptr = (tmp - metaSize()));
}

int validBlockAddress(void *ptr)
{
  if (g_block && (ptr > (void *)g_block && ptr < sbrk(0))) {
    return (ptr == (getBlock(ptr)->ptr));
  }
  return (0);
}

t_block *fusionBlocks(t_block *b)
{
  if (b->next && b->next->free) {
    b->size += metaSize() + b->next->size;
    b->next = b->next->next;

    if(b->next)
      b->next->prev = b;
  }

  return (b);
}


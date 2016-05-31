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

int blockSize(int n)
{
	return ((((n - 1) >> 2) << 2) + 4);
}

t_block* findBlock(t_block *chain, size_t size)
{
	t_block *b;
	
	b = chain;
	while (b && !(b->free && b->size >= size))
		b = b->next;
	
	return (b);
}

t_block* extendHeap(t_block *chain, size_t size)
{
	t_block *b;

	b = sbrk(0);
	if (sbrk(sizeof(t_block) + size) == (void*) -1)
		return (NULL);
	
	b->size = size;
	b->next = NULL;
	b->free = 0;
	if (chain)
		chain->next = b;
	
	return (b);
}

void split_block(t_block b, size_t size)
{
	t_block new;
	
	new = b->data + size;
	new->size = (b->size - size) - sizeof(t_block);
	new->next = b->next;
	new->free = 1;
	
	b->size = size;
	b->next = new;
}

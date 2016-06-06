/*
** _file_.c for main in /home/anzer_r/a/file/somewhere/
** 
** Made by ANZER ryan
** Login   <anzer_r@etna-alternance.net>
** 
** Started on  Fri Apr 17 10:36:53 2210 ANZER ryan
** Last update Sat Apr 18 13:55:35 2210 ANZER ryan
*/
#include "header.h"

extern t_block *g_block;

void *realloc(void *ptr, size_t s)
{
  size_t size;
  t_block *block;
  t_block *out;
  void *tmp;
  
  if (!ptr)
    return (malloc(s));
  
  if (validBlockAddress(ptr))
    {
      size = blockSize(s);
      block = getBlock(ptr);
      printf("realloc is good address %p\n", block);
      
      if (block->size >= size)
	{
	  printf("realloc asked smaller %lu, %lu, %lu\n", block->size, size, s);
	  if (block->size - size >= (metaSize() + 4))
	    {
	      printf("made smaller\n");
	      splitBlock(block, size);
	    }
	}
      else
	{
	  printf("realloc bigger \n");
	  if (block->next && block->next->free && (block->size + metaSize() + block->next->size) >= size)
	    {
	      printf("realloc found a block to fusion with\n");
	      block = fusionBlocks(block);
	      if (block->size - size >= (size_t)(metaSize() + 4))
		splitBlock(block, size);
	    }
	  else
	    {
	      printf("nothing found lets make new big for size %lu\n", s);
	      tmp = malloc(s);
	      if (!tmp || !(out = getBlock(tmp)))
		return (NULL);
	      //copyBlock(block, out);
	      printf("new block, %p %lu %lu\n", out, out->size, s);
	      free(ptr);
	      return (out->data);
	    }
	}
      printf("realloc out address %p %lu\n", block, block->size);
      return (block->data);
    }
  return (NULL);
}


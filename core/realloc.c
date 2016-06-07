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
      
      if (block->size >= size)
	{
	  if (block->size - size >= (metaSize() + 4))
	    splitBlock(block, size);
	}
      else
	{
	  if (block->next && block->next->free && (block->size + metaSize() + block->next->size) >= size)
	    {
	      block = fusionBlocks(block);
	      if (block->size - size >= (size_t)(metaSize() + 4))
		splitBlock(block, size);
	    }
	  else
	    {
	      tmp = malloc(s);
	      if (!tmp || !(out = getBlock(tmp)))
		return (NULL);
	      copyBlock(block, out);
	      free(ptr);
	      return (out->data);
	    }
	}
      return (block->data);
    }
  return (NULL);
}


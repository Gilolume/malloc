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

extern t_block *g_block;

void* calloc(size_t number, size_t size)
{
	t_block *out;
	int max;
	int i;
	
	if ((out = malloc(number * size))) {
		max = blockSize(number * size) << 2;
		while (i < max)
			{
				out[i] = 0;
				i += 1;
			}
	}
	
	return (out);
}

/*
** header.h for header in /home/anzer_r/project/dicowesh/anzer_r/discowesh/core
** 
** Made by ANZER ryan
** Login   <anzer_r@etna-alternance.net>
** 
** Started on  Fri Apr 17 10:38:11 2015 ANZER ryan
** Last update Sat Apr 18 12:24:36 2015 ANZER ryan
*/

#ifndef __HEADER__
#define __HEADER__

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <sys/stat.h>
#include <sys/socket.h>
#include <unistd.h>
#include <fcntl.h>

typedef struct s_block
{
  int free;
  size_t size;
  struct s_block *next;
  struct s_block *prev;
  void *ptr;
  
  char data[1];
} t_block;

void my_putchar(char c);
void my_putstr(char *str);
void my_put_nbr(int nb);

size_t metaSize();
size_t blockSize(int n);
t_block* findBlock(t_block **chain, size_t size);
t_block* extendHeap(t_block *chain, size_t size);
void splitBlock(t_block *b, size_t size);
t_block *getBlock(void *p);
int validBlockAddress(void *p);
t_block *fusionBlocks(t_block *b);
void copyBlock(t_block *a, t_block *b);

#endif

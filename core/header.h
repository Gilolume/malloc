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
#include <time.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <sys/stat.h>
#include <sys/socket.h>
#include <unistd.h>
#include <fcntl.h>

typedef struct s_list
{
  void *data;
  struct s_list *next;
} t_list;


typedef struct s_core
{
  t_socket *socket;
  
  t_list *cmd;
} t_core;

typedef struct s_word
{
  char *fr;
  char *wesh;
} t_word;

typedef struct s_command
{
  char *command;
  char *explain;
  void (*func)();
} t_command;

int my_strlen(char *str);
void my_put_nbr(int nbr);
void my_putchar(char c);
void my_putstr(char *str);
char *my_strdup(char *str);
int my_strcmp(char *s1, char *s2);
char **my_str_to_wordtab(char *str);

#endif

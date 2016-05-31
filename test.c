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

int main(int argc, char **argv)
{
	char *list;
	int i;
	
	list = malloc(sizeof(char) * 10);
	if (list) {
		i = 0;
		while (i < 5) {
			list[i] = 'a';
		}
		list[5] = '\0';
		list[6] = '\0';
		printf('%s\n', list);
	}
	
	return (0);
}

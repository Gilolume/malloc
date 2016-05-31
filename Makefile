SRC =	my_malloc.c

NAME =	libmy_malloc_Linux
OBJO =	$(SRC:%.c=%.o)
OBJC =	$(SRC)

CFLAGS 	= -W -Werror -Wall
LDFLAGS	= -shared

all:	$(NAME)

$(NAME):	$(OBJO)
	gcc $(OBJO) -o $(NAME) -L./lib_src -lmy
	ln -s libmy_malloc_Linux.so libmy_malloc.so

clean:
	rm -f $(OBJO)
fclean:		clean
	rm -f $(NAME)

re:	fclean all

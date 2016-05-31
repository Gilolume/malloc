SRC =	my_malloc.c\
  core/block.c \
  test.c

NAME =	libmy_malloc_Linux
OBJO =	$(SRC:%.c=%.o)
OBJC =	$(SRC)

CFLAGS 	= -W -Werror -Wall
LDFLAGS	= -shared

all:	$(NAME)

$(NAME):	$(OBJO)
	make -C lib_src/
	gcc $(OBJO) -o $(NAME) -L./lib_src -lmy
	ln -sf libmy_malloc_Linux.so libmy_malloc.so

clean:
	rm -f $(OBJO)
fclean:		clean
	rm -f $(NAME)
	rm -f libmy_malloc.so

re:	fclean all

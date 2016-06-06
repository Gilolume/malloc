SRC =	my_malloc.c\
	core/block.c\
	core/calloc.c\
	core/realloc.c

CC	= gcc
NAME 	= libmy_malloc_$(shell uname).so
OBJO 	= $(SRC:%.c=%.o)
OBJC 	= $(SRC)

CFLAGS 	= -W -Werror -Wall -fPIC
LDFLAGS	= -shared

all:	$(NAME)

$(NAME):	$(OBJO)
	make -C lib_src/
	$(CC) $(CFLAGS) $(OBJO) -o $(NAME) -L./lib_src -lmy $(LDFLAGS)
	ln -sf $(NAME) libmy_malloc.so

test: 	all
	$(CC) -W -Werror -Wall -o mallocTest test.c -L. -lmy_malloc -L./lib_src -lmy

clean:
	rm -f $(OBJO)
fclean:		clean
	rm -f $(NAME)
	rm -f libmy_malloc.so
	rm -f mallocTest
	make -C lib_src/ fclean

re:	fclean all

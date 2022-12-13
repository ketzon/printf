NAME = libftprintf.a
CFLAGS = -Wall -Wextra -Werror
SOURCES = printf.c put.c

all: $(NAME)

$(NAME): $(SOURCES:.c=.o)
	ar -rc libftprintf.a $(SOURCES:.c=.o)

clean:
	rm -f *.o

fclean: clean
	rm -f libftprintf.a

re: fclean all

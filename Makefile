NAME = libftprintf.a
CFLAGS = -Wall -Wextra -Werror
SOURCES = printf.c put.c

all: $(NAME)

$(NAME): $(SOURCES:.c=.o)
	ar -rc $(NAME) $(SOURCES:.c=.o)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

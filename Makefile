CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCS = main.c get_next_line.c get_next_line_util.c
OBJS = $(SRCS:.c=.o)
NAME = get_next_line
RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

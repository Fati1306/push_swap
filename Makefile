
NAME = push_swap

SRCS = push_swap.c function_utils/ft_atoi.c function_utils/ft_itoa.c function_utils/ft_putstr.c function_utils/ft_strlcpy.c list_utils/add_to_back.c list_utils/create_node.c list_utils/last_node.c list_utils/print_list.c

OBJS = $(SRCS:.c=.o)

CC = cc

CFLAGS = -Wall -Werror -Wextra

RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -I.

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I.

	
test:
	./push_swap 32 7 51

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re test
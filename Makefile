
NAME = push_swap

SRCS = push_swap.c sorting/sort_six_plus.c sorting/sort_five.c sorting/sort_four.c sorting/sort_three.c instructions/swap.c instructions/push.c instructions/rotate.c instructions/reverse_rotate.c function_utils/ft_atoi.c function_utils/ft_itoa.c function_utils/ft_strlcpy.c function_utils/ft_strcmp.c list_utils/add_to_back.c list_utils/create_node.c list_utils/last_node.c list_utils/print_list.c list_utils/free_list.c list_utils/before_last_node.c list_utils/index_stack.c list_utils/find_smallest_index.c list_utils/list_size.c checking/args_checking.c checking/stack_checking.c

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
	./push_swap 11 2 10 12 0 3 8 1 4 13 9 5 14 7 6

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re test
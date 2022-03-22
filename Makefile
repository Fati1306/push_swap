
NAME = push_swap

SRCS = push_swap.c sorting/sort_six_plus.c sorting/sort_five.c sorting/sort_four.c sorting/sort_three.c instructions/swap.c instructions/push.c instructions/rotate.c instructions/reverse_rotate.c instructions/check_instructions.c function_utils/ft_atoi.c function_utils/ft_itoa.c function_utils/ft_strlcpy.c function_utils/ft_strcmp.c list_utils/add_to_back.c list_utils/create_node.c list_utils/last_node.c list_utils/print_list.c list_utils/free_list.c list_utils/before_last_node.c list_utils/index_stack.c list_utils/find_smallest_index.c list_utils/list_size.c list_utils/index_of_node.c list_utils/push_side.c list_utils/last_node_index.c list_utils/search_for_index.c checking/args_checking.c checking/stack_checking.c

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
	./push_swap 14 45 48 34 40 26 1 5 20 0 25 32 12 9 49 36 18 41 33 4 50 30 39 13 21 19 43 31 22 7 44 11 35 23 42 28 2 15 8 24 17 37 46 27 10 3 47 16 6 38 29
#	./push_swap 2 1 13 8 12 6 14 4 7 0 10 9 5 11 3
#	./push_swap 17 13 16 22 2 8 20 10 1 6 12 3 7 23 18 9 14 19 4 0 5 15 11 21

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re test
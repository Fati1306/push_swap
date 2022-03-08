/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-maac <fel-maac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 16:48:12 by fel-maac          #+#    #+#             */
/*   Updated: 2022/03/08 17:57:06 by fel-maac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	init_stack_a(t_node **a_head, int ac, char **av)
{
	int		i;
	t_node	*new_node;

	i = 0;
	while (++i < ac)
	{
		if (i == 1)
			*a_head = create_node(ft_atoi(av[i]));
		else
		{
			new_node = create_node(ft_atoi(av[i]));
			add_to_back(a_head, new_node);
		}
	}
}

static void	sort_stack(int nums, t_node **a_head, t_node **b_head)
{
	if (nums == 2)
	{
		ra(a_head);
		return ;
	}
	else
		index_stack(a_head);
	if (nums == 3)
		sort_three(a_head);
	else if (nums == 4)
		sort_four(a_head, b_head);
	else if (nums == 5)
		sort_five(a_head, b_head);
	else
		sort_six_plus(a_head, b_head);
}

void	error_exit(void)
{
	write(3, "Error\n", 7);
	exit(1);
}

int	main(int ac, char **av)
{
	t_node	*a_head;
	t_node	*b_head;

	a_head = NULL;
	b_head = NULL;
	// printf("%s\n", av[1]);
	if (ac <= 2)
		exit(0);
	check_args(ac, av);
	init_stack_a(&a_head, ac, av);
	if (check_sorted_stack(a_head) == 0)
		return (0);
	// write(1, "\na list:\n", 9);
	// print_list(a_head);
	// // write(1, "\nb list:\n", 9);
	// // print_list(b_head);
	// write(1, "\n", 2);
	sort_stack(ac - 1, &a_head, &b_head);

	// b_head = create_node(3);
	// sa(&a_head);
	// sb(&b_head);
	// ss(&a_head, &b_head);
	// pa(&a_head, &b_head);
	// pb(&b_head, &a_head);
	// ra(&a_head);
	// rb(&b_head);
	// rr(&a_head, &b_head);
	// rra(&a_head);
	// rrb(&b_head);
	// rrr(&a_head, &b_head);
	// write(1, "\nnew a list:\n", 13);
	// print_list(a_head);
	// write(1, "\nnew b list:\n", 13);
	// print_list(b_head);

	// system("leaks push_swap");
	return (0);
}

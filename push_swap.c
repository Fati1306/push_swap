/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-maac <fel-maac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 16:48:12 by fel-maac          #+#    #+#             */
/*   Updated: 2022/03/04 18:40:59 by fel-maac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// to do
// add index to nodes
// write instructions

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

void	error_exit(void)
{
	write(3, "Error\n", 7);
	exit(1);
}

int	main(int ac, char **av)
{
	t_node	*a_head;
	t_node	*b_head;
	if (ac <= 1)
		exit(0);
	check_args(ac, av);
	init_stack_a(&a_head, ac, av);
	if (check_sorted_stack(a_head) == 0)
		return (0);
	print_list(a_head);
	sa(&a_head, &b_head);
	free_list(a_head);
	// system("leaks push_swap");
	return (0);
}

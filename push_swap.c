/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-maac <fel-maac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 16:48:12 by fel-maac          #+#    #+#             */
/*   Updated: 2022/03/22 17:27:31 by fel-maac         ###   ########.fr       */
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

void	init_i(t_i *i)
{
	i->sa = 0;
	i->sb = 0;
	i->pa = 0;
	i->pb = 0;
	i->ra = 0;
	i->rb = 0;
	i->rra = 0;
	i->rrb = 0;
}

static void	sort_stack(int nums, t_node **a_head, t_node **b_head)
{
	t_i	i;

	init_i(&i);
	if (nums == 2)
	{
		ra(a_head, &i);
		return ;
	}
	else
		index_stack(a_head);
	if (nums == 3)
		sort_three(a_head, &i);
	else if (nums == 4)
		sort_four(a_head, b_head, &i);
	else if (nums == 5)
		sort_five(a_head, b_head, &i);
	else
		sort_six_plus(a_head, b_head, &i);
	write_previous_instruction(&i);
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
	if (ac <= 2)
		exit(0);
	check_args(ac, av);
	init_stack_a(&a_head, ac, av);
	if (check_sorted_stack(a_head) == 0)
		return (0);
	sort_stack(ac - 1, &a_head, &b_head);
	return (0);
}
	// system("leaks push_swap");

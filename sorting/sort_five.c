/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-maac <fel-maac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 11:36:14 by fel-maac          #+#    #+#             */
/*   Updated: 2022/03/18 10:31:24 by fel-maac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	push_two_elm(t_node **a_head, t_node **b_head, int smallest_i)
{
	t_node	*lst;

	lst = *a_head;
	while (lst)
	{
		if (lst->index == smallest_i || lst->index == smallest_i + 1)
		{
			while ((*a_head)->index != lst->index)
			{
				if (lst->index > 2)
					rra(a_head);
				else
					ra(a_head);
			}
			lst = lst->next;
			pb(b_head, a_head);
		}
		else
			lst = lst->next;
	}
}

void	sort_five(t_node **a_head, t_node **b_head)
{
	int		smallest_index;

	if (check_sorted_stack(*a_head) == 0)
		return ;
	smallest_index = find_smallest_index(*a_head);
	push_two_elm(a_head, b_head, smallest_index);
	sort_three(a_head);
	pa(a_head, b_head);
	pa(a_head, b_head);
	if (check_sorted_stack(*a_head) != 0)
		sa(a_head);
}

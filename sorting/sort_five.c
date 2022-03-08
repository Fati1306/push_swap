/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-maac <fel-maac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 11:36:14 by fel-maac          #+#    #+#             */
/*   Updated: 2022/03/08 11:45:36 by fel-maac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	push_smallest_i(t_node **a_head, t_node **b_head, int smallest_i)
{
	t_node	*a_lst;
	int		lst_index;

	a_lst = *a_head;
	lst_index = 0;
	while (a_lst)
	{
		if (a_lst->index == smallest_i)
		{
			while ((*a_head)->index != smallest_i)
			{
				if (lst_index > 2)
					rra(a_head);
				else
					ra(a_head);
			}
			pb(b_head, a_head);
			break ;
		}
		lst_index++;
		a_lst = a_lst->next;
	}
}

void	sort_five(t_node **a_head, t_node **b_head)
{
	int		smallest_index;

	if (check_sorted_stack(*a_head) == 0)
		return ;
	smallest_index = find_smallest_index(*a_head);
	push_smallest_i(a_head, b_head, smallest_index);
	smallest_index = find_smallest_index(*a_head);
	push_smallest_i(a_head, b_head, smallest_index);
	sort_three(a_head);
	pa(a_head, b_head);
	pa(a_head, b_head);
}

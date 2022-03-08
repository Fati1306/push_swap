/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_four.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-maac <fel-maac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 17:44:11 by fel-maac          #+#    #+#             */
/*   Updated: 2022/03/07 19:53:43 by fel-maac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_four(t_node **a_head, t_node **b_head)
{
	t_node	*a_lst;
	int		smallest_index;

	smallest_index = find_smallest_index(*a_head);
	a_lst = *a_head;
	while (a_lst)
	{
		if (a_lst->index == smallest_index)
		{
			// pb(b_head, a_head);
			break ;
		}
		a_lst = a_lst->next;
	}
	sort_three(a_head);
	// pa(a_head, b_head);
	(void)b_head;
}

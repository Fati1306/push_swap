/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-maac <fel-maac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 10:16:54 by fel-maac          #+#    #+#             */
/*   Updated: 2022/03/08 11:29:44 by fel-maac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	set_index(int *min, int *mid, t_node **head)
{
	t_node	*l;

	l = *head;
	*min = find_smallest_index(*head);
	if (l->index < l->next->index && l->index < l->next->next->index)
	{
		if (l->next->index < l->next->next->index)
			*mid = l->next->index;
		else
			*mid = l->next->next->index;
	}
	else if (l->next->index < l->index && l->next->index < l->next->next->index)
	{
		if (l->index < l->next->next->index)
			*mid = l->index;
		else
			*mid = l->next->next->index;
	}
	else
	{
		if (l->index < l->next->index)
			*mid = l->index;
		else
			*mid = l->next->index;
	}
}

static void	sort_stack(int min, int mid, t_node **head)
{
	if ((*head)->index == min)
	{
		rra(head);
		sa(head);
	}
	else if ((*head)->index == mid)
	{
		if ((*head)->next->index == min)
			sa(head);
		else
			rra(head);
	}
	else
	{
		ra(head);
		if ((*head)->next->index == min)
			sa(head);
	}
}

void	sort_three(t_node **head)
{
	int	min;
	int	mid;

	if (check_sorted_stack(*head) == 0)
		return ;
	set_index(&min, &mid, head);
	sort_stack(min, mid, head);
}

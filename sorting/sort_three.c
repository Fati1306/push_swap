/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-maac <fel-maac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 10:16:54 by fel-maac          #+#    #+#             */
/*   Updated: 2022/03/21 17:05:35 by fel-maac         ###   ########.fr       */
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

static void	sort_stack(int min, int mid, t_node **head, t_i *i)
{
	if ((*head)->index == min)
	{
		rra(head, i);
		sa(head, i);
	}
	else if ((*head)->index == mid)
	{
		if ((*head)->next->index == min)
			sa(head, i);
		else
			rra(head, i);
	}
	else
	{
		ra(head, i);
		if ((*head)->next->index == min)
			sa(head, i);
	}
}

void	sort_three(t_node **head, t_i *i)
{
	int	min;
	int	mid;

	if (check_sorted_stack(*head) == 0)
		return ;
	set_index(&min, &mid, head);
	sort_stack(min, mid, head, i);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-maac <fel-maac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 10:16:54 by fel-maac          #+#    #+#             */
/*   Updated: 2022/03/07 18:13:30 by fel-maac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	set_index(int *min, int *mid, t_node **head)
{
	t_node	*l;

	l = *head;
	if (l->index < l->next->index && l->index < l->next->next->index)
	{
		*min = l->index;
		if (l->next->index < l->next->next->index)
			*mid = l->next->index;
		else
			*mid = l->next->next->index;
	}
	else if (l->next->index < l->index && l->next->index < l->next->next->index)
	{
		*min = l->next->index;
		if (l->index < l->next->next->index)
			*mid = l->index;
		else
			*mid = l->next->next->index;
	}
	else
	{
		*min = l->next->next->index;
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
		if ((*head)->next->index == min)
			ra(head);
		else
		{
			rra(head);
			rra(head);
			sa(head);
		}
	}
}

void	sort_three(t_node **head)
{
	int	min;
	int	mid;

	set_index(&min, &mid, head);
	sort_stack(min, mid, head);
	// if ((*head)->index == 0)
	// {
	// 	rra(head);
	// 	sa(head);
	// }
	// else if ((*head)->index == 1)
	// {
	// 	if ((*head)->next->index == 0)
	// 		sa(head);
	// 	else
	// 		rra(head);
	// }
	// else
	// {
	// 	if ((*head)->next->index == 0)
	// 		ra(head);
	// 	else
	// 	{
	// 		rra(head);
	// 		rra(head);
	// 		sa(head);
	// 	}
	// }
}
			// sa(head);
			// rra(head);
		// ra(head);

		// if ((*head)->next->index == 0)
		// 	sa(head);
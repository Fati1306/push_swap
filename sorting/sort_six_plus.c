/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_six_plus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-maac <fel-maac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 14:27:44 by fel-maac          #+#    #+#             */
/*   Updated: 2022/03/21 15:09:04 by fel-maac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	push_to_b(t_sort *s, t_node **a_head, t_node **b_head)
{
	push_side(*a_head, s, s->min, s->max);
	while (!((*a_head)->index >= s->min && (*a_head)->index <= s->max))
	{
		if (s->push_side)
			rra(a_head);
		else
			ra(a_head);
	}
		pb(b_head, a_head);
		if ((*b_head)->index < s->mid)
			rb(b_head);
}

static int	search_for_index(t_node **b_head, int index)
{
	t_node	*lst;

	lst = *b_head;
	while (lst)
	{
		if (lst->index == index)
			return (0);
		lst = lst->next;
	}
	return (1);
}

static void	push_wanted_index(int index, t_node **b_head, t_sort *s)
{
	push_side(*b_head, s, index, index);
		if (s->push_side)
			rrb(b_head);
		else
			rb(b_head);
}

static void	sort_rest(t_node **a_head, t_node **b_head, t_sort *s)
{
	int		index;

	s->faked_node = last_node(*a_head);
	s->last_n_index = s->faked_node->index;
	s->faked_node->index = -1;
	while (*b_head)
	{
		index = (*a_head)->index - 1;
		if (search_for_index(b_head, index) == 0)
		{
			if ((*b_head)->index < (*a_head)->index
				&& (*b_head)->index > last_node_index(*a_head))
			{
				pa(a_head, b_head);
				if ((*a_head)->index != index)
					ra(a_head);
			}
			else
				push_wanted_index(index, b_head, s);
		}
		else
			rra(a_head);
	}
	s->faked_node->index = s->last_n_index;
	while (check_sorted_stack(*a_head) != 0)
		rra(a_head);
}

void	sort_six_plus(t_node **a_head, t_node **b_head)
{
	t_sort	s;

	s.size = list_size(*a_head);
	while (s.size > 5)
	{
		s.to_push = (s.size - 5) / 3 + 1;
		s.min = find_smallest_index(*a_head);
		s.max = s.min + s.to_push - 1;
		s.mid = (s.min + s.max) / 2;
		while (s.to_push)
		{
			push_to_b(&s, a_head, b_head);
			s.to_push--;
		}
		s.size = list_size(*a_head);
	}
	sort_five(a_head, b_head);
	sort_rest(a_head, b_head, &s);
}

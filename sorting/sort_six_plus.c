/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_six_plus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-maac <fel-maac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 14:27:44 by fel-maac          #+#    #+#             */
/*   Updated: 2022/03/18 10:08:49 by fel-maac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	push_to_b(t_sort *s, t_node **a_head, t_node **b_head)
{
	t_node	*lst;

	lst = *a_head;
	while (lst)
	{
		if (lst->index >= s->min && lst->index <= s->max)
		{
			while ((*a_head)->index != lst->index)
			{
				if (lst->index > (s->size - s->total_pushed) / 2)
					ra(a_head);
				else
					rra(a_head);
			}
			pb(b_head, a_head);
			if ((*b_head)->index < s->mid)
				rb(b_head);
			s->total_pushed++;
			break ;
		}
		lst = lst->next;
	}
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

static void	push_to_a(int index, t_node **a_head, t_node **b_head)
{
	int	size;
	int		i;
	t_node	*b_lst;

	size = list_size(*b_head);
	i = 0;
	b_lst = *b_head;
	while (b_lst)
	{
		if (b_lst->index == index)
		{
			while ((*b_head)->index != index)
			{
				if (i > size / 2)
					rrb(b_head);
				else
					rb(b_head);
			}
			pa(a_head, b_head);
			return ;
		}
		b_lst = b_lst->next;
		i++;
	}
}

static void	sort_rest(t_node **a_head, t_node **b_head, t_sort *s)
{
	int		index;
	t_node	*last_n;

	s->faked_node = last_node(*a_head);
	s->last_n_index = s->faked_node->index;
	s->faked_node->index = -1;
	while (*b_head)
	{
		index = (*a_head)->index - 1;
		last_n = last_node(*a_head);
		if (search_for_index(b_head, index) == 0)
		{
			if ((*b_head)->index < (*a_head)->index
				&& (*b_head)->index > last_n->index)
			{
				pa(a_head, b_head);
				if ((*a_head)->index != index)
					ra(a_head);
			}
			else
				push_to_a(index, a_head, b_head);
		}
		else
			rra(a_head);
	}
	s->faked_node->index = s->last_n_index;
	while (check_sorted_stack(*a_head) != 0)
		rra(a_head);
}

	// write(1, "\na list:\n", 10);
	// print_list(*a_head);
	// write(1, "\nb list:\n", 10);
	// print_list(*b_head);
	// size = list_size(*a_head);
	
		// index = (*a_head)->index - 1;
		// if ((*b_head)->index <= index && (*b_head)->index > last_n->index)
		// {
		// 	if ((*b_head)->index == index)
		// 		pa(a_head, b_head);
		// 	else
		// 		rb(b_head);
		// }
		// else
		// {
		// 	while ((*b_head)->index != index)
		// 		rb(b_head);
		// }
		// if ((*b_head)->next == NULL)
		// 	pa(a_head, b_head);

// static void	sort_rest(t_node **a_head, t_node **b_head)
// {
// 	int		index;
// 	t_node	*b_lst;

// 	b_lst = *b_head;
// 	while (*b_head)
// 	{
// 		index = (*a_head)->index - 1;
// 		if ((*b_head)->index == index)
// 			pa(a_head, b_head);
// 		// else if ()
// 		// 	sb(b_head);
// 		else
// 			break ;
// 	}
// }
// while b_head
// if b_head index = a_head index - 1 push to a
// else if a_head index - 1 > total pushed / 2
// rotate til b_head index == a head index -1

void	sort_six_plus(t_node **a_head, t_node **b_head)
{
	t_sort	s;

	s.size = list_size(*a_head);
	s.total_pushed = 0;
	while (s.size > 5)
	{
		s.to_push = (s.size - 5) / 3 + 1;
		s.min = find_smallest_index(*a_head);
		s.max = s.min + s.to_push - 1;
		s.mid = (s.min + s.max) / 2;
		push_to_b(&s, a_head, b_head);
		s.size = list_size(*a_head);
	}
	sort_five(a_head, b_head);
	sort_rest(a_head, b_head, &s);
}

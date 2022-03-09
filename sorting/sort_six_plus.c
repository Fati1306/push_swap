/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_six_plus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-maac <fel-maac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 14:27:44 by fel-maac          #+#    #+#             */
/*   Updated: 2022/03/08 18:45:39 by fel-maac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	push_elements(t_sort *s, t_node **a_head, t_node **b_head, t_node *lst)
{
	while (lst)
	{
		if (lst->index >= s->min && lst->index <= s->max)
		{
			while ((*a_head)->index != lst->index)
			{
				if (lst->index > (s->size - s->total_pushed) / 2)
					rra(a_head);
				else
					ra(a_head);
			}
			pb(b_head, a_head);
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

static void	sort_rest(t_node **a_head, t_node **b_head)
{
	int		index;
	t_node	*b_lst;
	t_node	*last_n;

	b_lst = *b_head;
	last_n = last_node(*a_head);
	last_n->index = -1;
	while (*b_head)
	{
		index = (*a_head)->index - 1;
		if (search_for_index(b_head, index) == 0)
		{
			if ((*b_head)->index < (*a_head)->index
				&& (*b_head)->index > last_n->index)
				pa(a_head, b_head);
			if ((*a_head)->index != index)
				ra(a_head);
			else
			{
				//  push the wanted element to the top of the helping stack using the closest path
                // either by rotating or reverse rotating. then push to a
			}
		}
		else
		{
		// it is at the end of the stack
            // reverse rotate element in stack then push to a
		}
	}
	//   UNFAKE the last element
	//     WHILE the stack isn't sorted yet, reverse rotate

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
}

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
	t_node	*lst;

	s.size = list_size(*a_head);
	s.total_pushed = 0;
	while (s.size > 5)
	{
		lst = *a_head;
		s.to_push = (s.size - 5) / 3 + 1;
		s.min = find_smallest_index(*a_head);
		s.max = s.min + s.to_push - 1;
		s.mid = (s.min + s.max) / 2;
		push_elements(&s, a_head, b_head, lst);
		s.size = list_size(*a_head);
	}
	sort_five(a_head, b_head);
	sort_rest(a_head, b_head);
}

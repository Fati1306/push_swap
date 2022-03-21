/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_side.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-maac <fel-maac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 10:50:42 by fel-maac          #+#    #+#             */
/*   Updated: 2022/03/21 11:37:01 by fel-maac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push_side(t_node *head, t_sort *s, int min, int max)
{
	t_node	*tail;

	tail = last_node(head);
	while (!(head->index >= min && head->index <= max)
		&& !(tail->index >= min && tail->index <= max))
	{
		head = head->next;
		tail = tail->previous;
	}
	if (head->index >= min && head->index <= max)
		s->push_side = 0;
	else if (tail->index >= min && tail->index <= max)
		s->push_side = 1;
}

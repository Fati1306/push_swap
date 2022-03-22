/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-maac <fel-maac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 13:15:03 by fel-maac          #+#    #+#             */
/*   Updated: 2022/03/21 17:44:17 by fel-maac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	reverse_rotate(t_node **head)
{
	t_node	*temp;

	if (*head && (*head)->next)
	{
		temp = before_last_node(*head);
		temp->next->next = *head;
		*head = temp->next;
		temp->next = NULL;
		(*head)->previous = NULL;
		(*head)->next->previous = *head;
	}
}

void	rra(t_node **a_head, t_i *i)
{
	i->rra++;
	reverse_rotate(a_head);
	check_instructions(i, 1);
}

void	rrb(t_node **b_head, t_i *i)
{
	i->rrb++;
	reverse_rotate(b_head);
	check_instructions(i, 1);
}

void	rrr(t_node **a_head, t_node **b_head, t_i *i)
{
	reverse_rotate(a_head);
	reverse_rotate(b_head);
	check_instructions(i, 1);
	write(1, "rrr\n", 4);
}

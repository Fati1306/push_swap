/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-maac <fel-maac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 13:15:03 by fel-maac          #+#    #+#             */
/*   Updated: 2022/03/29 11:15:15 by fel-maac         ###   ########.fr       */
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
	else
		error_exit();
}

void	rra(t_node **a_head, t_i *i)
{
	reverse_rotate(a_head);
	i->rra++;
	if (!check_instructions(i))
	{
		i->rra--;
		write_previous_instruction(i);
		i->rra = 1;
	}
}

void	rrb(t_node **b_head, t_i *i)
{
	reverse_rotate(b_head);
	i->rrb++;
	if (!check_instructions(i))
	{
		i->rrb--;
		write_previous_instruction(i);
		i->rrb = 1;
	}
}

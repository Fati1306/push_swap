/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-maac <fel-maac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 11:24:58 by fel-maac          #+#    #+#             */
/*   Updated: 2022/03/21 17:44:07 by fel-maac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	rotate(t_node **head)
{
	t_node	*temp;

	if (*head && (*head)->next)
	{
		temp = last_node(*head);
		temp->next = *head;
		temp->next->previous = temp;
		*head = (*head)->next;
		(*head)->previous = NULL;
		temp->next->next = NULL;
	}
}

void	ra(t_node **a_head, t_i *i)
{
	i->ra++;
	rotate(a_head);
	check_instructions(i, 1);
}

void	rb(t_node **b_head, t_i *i)
{
	i->rb++;
	rotate(b_head);
	check_instructions(i, 1);
}

void	rr(t_node **a_head, t_node **b_head, t_i *i)
{
	rotate(a_head);
	rotate(b_head);
	check_instructions(i, 1);
	write(1, "rr\n", 3);
}

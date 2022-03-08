/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-maac <fel-maac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 11:24:58 by fel-maac          #+#    #+#             */
/*   Updated: 2022/03/08 10:56:35 by fel-maac         ###   ########.fr       */
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
		*head = (*head)->next;
		temp->next->next = NULL;
	}
}

void	ra(t_node **a_head)
{
	rotate(a_head);
	write(1, "ra\n", 3);
}

void	rb(t_node **b_head)
{
	rotate(b_head);
	write(1, "rb\n", 3);
}

void	rr(t_node **a_head, t_node **b_head)
{
	rotate(a_head);
	rotate(b_head);
	write(1, "rr\n", 3);
}

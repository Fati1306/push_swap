/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-maac <fel-maac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 13:15:03 by fel-maac          #+#    #+#             */
/*   Updated: 2022/03/29 14:45:20 by fel-maac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker_bonus.h"

static void	reverse_rotate(t_node **head)
{
	t_node	*temp;

	if (*head && (*head)->next)
	{
		temp = before_last_node(*head);
		temp->next->next = *head;
		*head = temp->next;
		temp->next = NULL;
	}
}

void	rra_b(t_node **a_head)
{
	reverse_rotate(a_head);
}

void	rrb_b(t_node **b_head)
{
	reverse_rotate(b_head);
}	

void	rrr_b(t_node **a_head, t_node **b_head)
{
	reverse_rotate(a_head);
	reverse_rotate(b_head);
}

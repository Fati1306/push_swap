/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-maac <fel-maac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 10:44:59 by fel-maac          #+#    #+#             */
/*   Updated: 2022/03/29 14:44:13 by fel-maac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker_bonus.h"

static void	swap(t_node **head)
{
	t_node	*new_head;

	if (*head && (*head)->next)
	{
		new_head = (*head)->next;
		(*head)->next = (*head)->next->next;
		new_head->next = *head;
		*head = new_head;
	}
}

void	sa_b(t_node **a_head)
{
	swap(a_head);
}

void	sb_b(t_node **b_head)
{
	swap(b_head);
}

void	ss_b(t_node **a_head, t_node **b_head)
{
	swap(a_head);
	swap(b_head);
}

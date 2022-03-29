/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-maac <fel-maac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 10:44:59 by fel-maac          #+#    #+#             */
/*   Updated: 2022/03/25 14:59:33 by fel-maac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	swap(t_node **head)
{
	t_node	*new_head;

	if (*head && (*head)->next)
	{
		new_head = (*head)->next;
		new_head->previous = NULL;
		(*head)->next = (*head)->next->next;
		if ((*head)->next)
			(*head)->next->previous = (*head);
		(*head)->previous = new_head;
		new_head->next = *head;
		*head = new_head;
	}
	else
		error_exit();
}

void	sa(t_node **a_head, t_i *i)
{
	write_previous_instruction(i);
	swap(a_head);
	i->sa = 1;
}

void	sb(t_node **b_head, t_i *i)
{
	write_previous_instruction(i);
	swap(b_head);
	i->sb = 1;
}

void	ss(t_node **a_head, t_node **b_head, t_i *i)
{
	swap(a_head);
	swap(b_head);
	write_previous_instruction(i);
	write(1, "ss\n", 3);
}

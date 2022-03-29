/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-maac <fel-maac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 11:24:58 by fel-maac          #+#    #+#             */
/*   Updated: 2022/03/29 11:14:57 by fel-maac         ###   ########.fr       */
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
	else
		error_exit();
}

void	ra(t_node **a_head, t_i *i)
{
	rotate(a_head);
	i->ra++;
	if (!check_instructions(i))
	{
		i->ra--;
		write_previous_instruction(i);
		i->ra = 1;
	}
}

void	rb(t_node **b_head, t_i *i)
{
	rotate(b_head);
	i->rb++;
	if (!check_instructions(i))
	{
		i->rb--;
		write_previous_instruction(i);
		i->rb = 1;
	}
}

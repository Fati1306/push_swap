/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-maac <fel-maac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 13:15:03 by fel-maac          #+#    #+#             */
/*   Updated: 2022/03/24 06:43:46 by fel-maac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker_bonus.h"

static void	reverse_rotate(t_node **head, char **inst, char **p)
{
	t_node	*temp;

	if (*head && (*head)->next)
	{
		temp = before_last_node(*head);
		temp->next->next = *head;
		*head = temp->next;
		temp->next = NULL;
	}
	else
		free_and_exit(2, inst, p);
}

void	rra_b(t_node **a_head, char **inst, char **p)
{
	reverse_rotate(a_head, inst, p);
}

void	rrb_b(t_node **b_head, char **inst, char **p)
{
	reverse_rotate(b_head, inst, p);
}	

void	rrr_b(t_node **a_head, t_node **b_head, char **inst, char **p)
{
	reverse_rotate(a_head, inst, p);
	reverse_rotate(b_head, inst, p);
}

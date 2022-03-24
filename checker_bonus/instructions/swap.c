/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-maac <fel-maac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 10:44:59 by fel-maac          #+#    #+#             */
/*   Updated: 2022/03/24 06:44:00 by fel-maac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker_bonus.h"

static void	swap(t_node **head, char **inst, char **p)
{
	t_node	*new_head;

	if (*head && (*head)->next)
	{
		new_head = (*head)->next;
		(*head)->next = (*head)->next->next;
		new_head->next = *head;
		*head = new_head;
	}
	else
		free_and_exit(2, inst, p);
}

void	sa_b(t_node **a_head, char **inst, char **p)
{
	swap(a_head, inst, p);
}

void	sb_b(t_node **b_head, char **inst, char **p)
{
	swap(b_head, inst, p);
}

void	ss_b(t_node **a_head, t_node **b_head, char **inst, char **p)
{
	swap(a_head, inst, p);
	swap(b_head, inst, p);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-maac <fel-maac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 11:24:58 by fel-maac          #+#    #+#             */
/*   Updated: 2022/03/24 06:43:52 by fel-maac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker_bonus.h"

static void	rotate(t_node **head, char **inst, char **p)
{
	t_node	*temp;

	if (*head && (*head)->next)
	{
		temp = last_node(*head);
		temp->next = *head;
		*head = (*head)->next;
		temp->next->next = NULL;
	}
	else
		free_and_exit(2, inst, p);

}

void	ra_b(t_node **a_head, char **inst, char **p)
{
	rotate(a_head, inst, p);
}

void	rb_b(t_node **b_head, char **inst, char **p)
{
	rotate(b_head, inst, p);
}

void	rr_b(t_node **a_head, t_node **b_head, char **inst, char **p)
{
	rotate(a_head, inst, p);
	rotate(b_head, inst, p);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-maac <fel-maac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 11:12:45 by fel-maac          #+#    #+#             */
/*   Updated: 2022/03/24 16:35:52 by fel-maac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker_bonus.h"

static void	push(t_node **first_head, t_node **second_head, char **in, char **p)
{
	t_node	*temp;

	if (*second_head)
	{
		temp = *second_head;
		*second_head = (*second_head)->next;
		temp->next = *first_head;
		*first_head = temp;
	}
	else
		free_and_exit(2, in, p);
}

void	pa_b(t_node **a_head, t_node **b_head, char **inst, char **p)
{
	push(a_head, b_head, inst, p);
}

void	pb_b(t_node **b_head, t_node **a_head, char **inst, char **p)
{
	push(b_head, a_head, inst, p);
}

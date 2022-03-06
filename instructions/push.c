/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-maac <fel-maac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 11:12:45 by fel-maac          #+#    #+#             */
/*   Updated: 2022/03/06 11:25:36 by fel-maac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	push(t_node **first_head, t_node **second_head)
{
	t_node	*temp;
	
	if (second_head)
	{
		temp = *second_head;
		*second_head = (*second_head)->next;
		temp->next = *first_head;
		*first_head = temp;
	}
}

void	pa(t_node **a_head, t_node **b_head)
{
	push(a_head, b_head);
	write(1, "pa\n", 4);
}

void	pb(t_node **b_head, t_node **a_head)
{
	push(b_head, a_head);
	write(1, "pb\n", 4);
}

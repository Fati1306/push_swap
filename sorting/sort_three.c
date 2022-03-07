/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-maac <fel-maac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 10:16:54 by fel-maac          #+#    #+#             */
/*   Updated: 2022/03/07 11:19:50 by fel-maac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_node **head)
{
	if ((*head)->index == 0)
	{
		rra(head);
		sa(head);
	}
	else if ((*head)->index == 1)
	{
		if ((*head)->next->index == 0)
			sa(head);
		else
			rra(head);
	}
	else
	{
		ra(head);
		if ((*head)->next->index == 0)
			sa(head);
	}
}

// 021
// // if index is 0: rra, sa
// 102
// // if index is 1 & next index is 0: sa
// 120
// // if index is 1 / else: rra
// 201
// // if index is 2 & next index is 0: ra
// 210
// // if index is 2 / else: ra, sa

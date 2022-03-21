/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_for_index.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-maac <fel-maac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 15:18:22 by fel-maac          #+#    #+#             */
/*   Updated: 2022/03/21 15:18:49 by fel-maac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	search_for_index(t_node **b_head, int index)
{
	t_node	*lst;

	lst = *b_head;
	while (lst)
	{
		if (lst->index == index)
			return (0);
		lst = lst->next;
	}
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-maac <fel-maac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 14:15:17 by fel-maac          #+#    #+#             */
/*   Updated: 2022/03/07 10:15:52 by fel-maac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	index_stack(t_node **head)
{
	t_node	*node_to_index;
	t_node	*lst;

	node_to_index = *head;
	while (node_to_index)
	{
		lst = *head;
		while (lst)
		{
			if (node_to_index->data > lst->data)
				node_to_index->index++;
			lst = lst->next;
		}
		node_to_index = node_to_index->next;
	}
}

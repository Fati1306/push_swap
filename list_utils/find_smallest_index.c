/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_smallest_index.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-maac <fel-maac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 18:15:45 by fel-maac          #+#    #+#             */
/*   Updated: 2022/03/07 18:20:51 by fel-maac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	find_smallest_index(t_node *lst)
{
	int	smallest;

	smallest = lst->index;
	while (lst)
	{
		if (lst->index < smallest)
			smallest = lst->index;
		lst = lst->next;
	}
	return (smallest);
}

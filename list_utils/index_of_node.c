/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_of_node.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-maac <fel-maac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 13:18:57 by fel-maac          #+#    #+#             */
/*   Updated: 2022/03/21 15:15:39 by fel-maac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	index_of_node(t_node *lst, int data)
{
	int	i;

	i = 0;
	while (lst)
	{
		if (lst->data == data)
			return (i);
		i++;
		lst = lst->next;
	}
	return (-1);
}

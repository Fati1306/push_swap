/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   before_last_node.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-maac <fel-maac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 13:20:23 by fel-maac          #+#    #+#             */
/*   Updated: 2022/03/06 13:27:47 by fel-maac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_node	*before_last_node(t_node *lst)
{
	if (lst)
	{
		while (lst->next->next != NULL)
		{
			lst = lst->next;
		}
	}
	return (lst);
}

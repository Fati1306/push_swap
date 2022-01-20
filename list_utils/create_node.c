/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-maac <fel-maac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 14:42:55 by fel-maac          #+#    #+#             */
/*   Updated: 2022/01/20 14:46:39 by fel-maac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_node	*create_node(int data)
{
	t_node	*new_element;

	new_element = (t_node *) malloc(sizeof(t_node));
	if (new_element == NULL)
		return (NULL);
	new_element->prev = NULL;
	new_element->data = data;
	new_element->next = NULL;
	return (new_element);
}

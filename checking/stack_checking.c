/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_checking.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-maac <fel-maac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 18:02:15 by fel-maac          #+#    #+#             */
/*   Updated: 2022/03/04 18:32:42 by fel-maac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	check_sorted_stack(t_node *list)
{
	int	num;

	num = list->data;
	while (list->next)
	{
		list = list->next;
		if (num >= list->data)
			return (1);
		num = list->data;
	}
	return (0);
}

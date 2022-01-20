/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-maac <fel-maac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 15:02:47 by fel-maac          #+#    #+#             */
/*   Updated: 2022/01/20 15:04:56 by fel-maac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	print_list(t_node *lst)
{
	if (lst)
	{
		while (lst != NULL)
		{
			ft_putstr(ft_itoa((lst->data)));
			ft_putstr("\n");
			lst = lst->next;
		}
	}
}

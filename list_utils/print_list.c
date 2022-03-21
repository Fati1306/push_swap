/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-maac <fel-maac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 15:02:47 by fel-maac          #+#    #+#             */
/*   Updated: 2022/03/21 15:15:21 by fel-maac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

#include <stdio.h>

void	print_list(t_node *lst)
{
	char	*str;

	if (lst)
	{
		while (lst != NULL)
		{
			str = ft_itoa((lst->data));
			printf("value: %s\tindex: %i\n", str, lst->index);
			free(str);
			lst = lst->next;
		}
	}
}

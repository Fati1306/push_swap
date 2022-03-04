/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-maac <fel-maac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 15:02:47 by fel-maac          #+#    #+#             */
/*   Updated: 2022/03/04 15:41:52 by fel-maac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	print_list(t_node *lst)
{
	char	*str;
	if (lst)
	{
		while (lst != NULL)
		{
			str = ft_itoa((lst->data));
			ft_putstr(str);
			ft_putstr("\n");
			free(str);
			lst = lst->next;
		}
	}
}

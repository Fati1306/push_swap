/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-maac <fel-maac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 18:40:30 by fel-maac          #+#    #+#             */
/*   Updated: 2022/03/24 17:39:55 by fel-maac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	init_stack_a(t_node **a_head, int ac, char **av, int check)
{
	int		i;
	t_node	*new_node;

	if (!check)
		i = -1;
	else
		i = 0;
	while (++i < ac)
	{
		if ((!check && i == -1) || (check == 1 && i == 0))
			*a_head = create_node(ft_atoi(av[i]));
		else
		{
			new_node = create_node(ft_atoi(av[i]));
			add_to_back(a_head, new_node);
		}
	}
}

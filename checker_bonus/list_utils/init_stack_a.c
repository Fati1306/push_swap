/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-maac <fel-maac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 18:40:30 by fel-maac          #+#    #+#             */
/*   Updated: 2022/03/23 14:38:59 by fel-maac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker_bonus.h"

void	init_stack_a(t_node **a_head, int ac, char **av)
{
	int		i;
	t_node	*new_node;

	i = 0;
	while (++i < ac)
	{
		if (i == 1)
			*a_head = create_node(ft_atoi(av[i]));
		else
		{
			new_node = create_node(ft_atoi(av[i]));
			add_to_back(a_head, new_node);
		}
	}
}

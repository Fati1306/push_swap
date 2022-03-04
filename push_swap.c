/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-maac <fel-maac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 16:48:12 by fel-maac          #+#    #+#             */
/*   Updated: 2022/03/04 11:53:02 by fel-maac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	int		i;
	t_node	*new_node;
	t_node	*head;

	i = 0;
	if (ac <= 1)
		return (0);
	// arg_check();
	while (++i < ac)
	{
		if (i == 1)
			head = create_node(ft_atoi(av[i]));
		else
		{
			new_node = create_node(ft_atoi(av[i]));
			add_to_back(&head, new_node);
		}
	}
	print_list(head);
	// system("leaks a.out");
	return (0);
}

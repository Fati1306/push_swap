/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_av.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-maac <fel-maac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 16:45:39 by fel-maac          #+#    #+#             */
/*   Updated: 2022/03/24 17:53:39 by fel-maac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	parse_av(t_node **a_head, char **av, char ***args)
{
	int		i;
	int		len;

	i = 0;
	len = 0;
	*args = ft_split(av[1], ' ');
	if (*args == NULL)
		error_exit();
	while ((*args)[len])
		len++;
	check_args(len, *args, 0);
	init_stack_a(a_head, len, *args, 0);
}

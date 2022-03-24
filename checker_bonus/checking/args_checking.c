/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_checking.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-maac <fel-maac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 14:53:34 by fel-maac          #+#    #+#             */
/*   Updated: 2022/03/23 14:37:59 by fel-maac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker_bonus.h"

static void	check_if_int(int ac, char **av)
{
	int	i;

	while (--ac)
	{
		i = 0;
		while (av[ac][i])
		{
			if ((av[ac][i] >= '0' && av[ac][i] <= '9')
				|| (i == 0 && av[ac][i] == '-') || (i == 0 && av[ac][i] == '+'))
				i++;
			else
				error_exit();
		}
	}
}

static void	check_duplicates(int ac, char **av)
{
	int		j;

	while (--ac)
	{
		j = 1;
		while (j < ac)
		{
			if (ft_strcmp(av[ac], av[j]) == 0)
				error_exit();
			j++;
		}
	}
}

static void	check_if_empty(int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (av[i][0] == '\0')
			error_exit();
		i++;
	}
}

void	check_args(int ac, char **av)
{
	check_if_empty(ac, av);
	check_if_int(ac, av);
	check_duplicates(ac, av);
}

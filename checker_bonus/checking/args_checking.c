/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_checking.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-maac <fel-maac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 14:53:34 by fel-maac          #+#    #+#             */
/*   Updated: 2022/03/24 17:56:14 by fel-maac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker_bonus.h"

static void	check_if_int(int ac, char **av, int check)
{
	int	i;
	int	l;

	if (!check)
		l = 0;
	else
		l = 1;
	while (l < ac)
	{
		i = 0;
		while (av[l][i])
		{
			if ((av[l][i] >= '0' && av[l][i] <= '9')
				|| (i == 0 && av[l][i] == '-') || (i == 0 && av[l][i] == '+'))
				i++;
			else
				error_exit();
		}
		l++;
	}
}

static void	check_duplicates(int ac, char **av, int check)
{
	int	j;

	while (--ac)
	{
		if (!check)
			j = 0;
		else
			j = 1;
		while (j < ac)
		{
			if (ft_strcmp(av[ac], av[j]) == 0)
				error_exit();
			j++;
		}
	}
}

static void	check_if_empty(int ac, char **av, int check)
{
	int	i;

	if (!check)
		i = 0;
	else
		i = 1;
	while (i < ac)
	{
		if (av[i][0] == '\0')
			error_exit();
		i++;
	}
}

void	check_args(int ac, char **av, int check)
{
	check_if_empty(ac, av, check);
	check_if_int(ac, av, check);
	check_duplicates(ac, av, check);
}

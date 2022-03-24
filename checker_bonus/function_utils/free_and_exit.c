/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_and_exit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-maac <fel-maac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 18:06:16 by fel-maac          #+#    #+#             */
/*   Updated: 2022/03/24 06:43:21 by fel-maac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker_bonus.h"

void	free_and_exit(int x, char **inst, char **p)
{
	free(*inst);
	free(*p);
	if (x == 0)
		write(1, "OK\n", 3);
	else if (x == 1)
		write(1, "KO\n", 3);
	else if (x == 2)
		error_exit();
	exit(0);
}

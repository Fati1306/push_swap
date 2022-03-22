/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_instructions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-maac <fel-maac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 17:18:21 by fel-maac          #+#    #+#             */
/*   Updated: 2022/03/21 17:50:33 by fel-maac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	check_instructions(t_i *i, int check)
{
	if (!check)
	{
		if (i->ra == 1)
			write(1, "ra\n", 3);
		if (i->rb == 1)
			write(1, "rb\n", 3);
		if (i->rra == 1)
			write(1, "rra\n", 4);
		if (i->rrb == 1)
			write(1, "rrb\n", 4);
		init_i(i);
		return ;
	}
	else
	{
		if (i->ra == 1 && i->rb == 1)
		{
			write(1, "rr\n", 3);
			init_i(i);
		}
		else if (i->ra > 1)
		{
			write(1, "ra\n", 3);
			i->ra = 1;
		}
		else if (i->rb > 1)
		{
			write(1, "ra\n", 3);
			i->rb = 1;
		}
		else if (i->rra == 1 && i->rrb == 1)
		{
			write(1, "rrr\n", 4);
			init_i(i);
		}
		else if (i->rra > 1)
		{
			write(1, "rra\n", 4);
			i->rra = 1;
		}
		else if (i->rrb > 1)
		{
			write(1, "rrb\n", 4);
			i->rrb = 1;
		}
	}
}

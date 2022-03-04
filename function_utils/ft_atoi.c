/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-maac <fel-maac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 11:52:13 by fel-maac          #+#    #+#             */
/*   Updated: 2022/01/20 14:31:17 by fel-maac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	check_spaces_sign(const char *str, int *i, int *sign)
{
	while (str[*i] == 32 || (str[*i] >= 9 && str[*i] <= 13))
		(*i)++;
	if (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
			*sign *= -1;
		(*i)++;
	}
}

int	ft_atoi(const char *str)
{
	int				i;
	unsigned long	num;
	int				sign;

	i = 0;
	num = 0;
	sign = 1;
	check_spaces_sign(str, &i, &sign);
	while (str[i] >= '0' && str[i] <= '9')
	{
		num *= 10;
		num += str[i] - '0';
		if (num > 9223372036854775807)
		{
			if (sign < 0)
				return (0);
			return (-1);
		}
		i++;
	}
	return (num * sign);
}

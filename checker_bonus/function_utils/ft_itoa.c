/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-maac <fel-maac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 13:04:40 by fel-maac          #+#    #+#             */
/*   Updated: 2022/03/23 14:43:16 by fel-maac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker_bonus.h"

static void	ft_fill_string(char *s, int len, int n)
{
	while (len > 0)
	{
		s[len - 1] = n % 10 + '0';
		n /= 10;
		len--;
	}
}

static int	ft_count_digits(int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static char	*ft_itoa_neg(int n)
{
	int		len;
	char	*s;

	len = 0;
	s = NULL;
	if (n == -2147483648)
	{
		s = (char *) malloc(sizeof(char) * 12);
		ft_strlcpy(s, "-2147483648", 12);
		return (s);
	}
	len = ft_count_digits(n);
	s = (char *) malloc(sizeof(char) * len + 2);
	if (s == NULL)
		return (NULL);
	s[++len] = '\0';
	n *= -1;
	ft_fill_string(s, len, n);
	s[0] = '-';
	return (s);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*s;

	len = 0;
	s = NULL;
	if (n < 0)
		s = ft_itoa_neg(n);
	else
	{
		len = ft_count_digits(n);
		s = (char *) malloc(sizeof(char) * len + 1);
		if (s == NULL)
			return (NULL);
		s[len] = '\0';
		ft_fill_string(s, len, n);
	}
	return (s);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkeskin <kkeskin@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 13:00:19 by kkeskin           #+#    #+#             */
/*   Updated: 2025/06/18 13:00:19 by kkeskin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putnbr_r(int n, int *chars)
{
	if (n > 9)
	{
		ft_putnbr_r((n / 10), chars);
		ft_putnbr_r((n % 10), chars);
	}
	else
	{
		ft_putchar(n + '0');
		(*chars)++;
	}
}

int	ft_putnbr(int n)
{
	int	chars;

	chars = 0;
	if (n == INT_MIN)
	{
		ft_putstr("-2147483648");
		return (11);
	}
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
		chars++;
	}
	if (n > 9)
	{
		ft_putnbr_r(n, &chars);
	}
	else
	{
		ft_putchar(n + '0');
		chars++;
	}
	return (chars);
}

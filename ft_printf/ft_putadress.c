/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putadress.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkeskin <kkeskin@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 12:59:11 by kkeskin           #+#    #+#             */
/*   Updated: 2025/06/18 12:59:12 by kkeskin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_puthex_ptr(unsigned long long n, int *chars)
{
	if (n > 15)
		ft_puthex_ptr(n / 16, chars);
	*chars += ft_putchar(HEXA_LOWER[n % 16]);
}

int	ft_putadress(void *p)
{
	int	chars;

	if (!p)
		return (ft_putstr("(nil)"));
	chars = 0;
	chars += ft_putstr("0x");
	ft_puthex_ptr((unsigned long long)p, &chars);
	return (chars);
}

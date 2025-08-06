/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkeskin <kkeskin@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 12:57:30 by kkeskin           #+#    #+#             */
/*   Updated: 2025/06/18 12:57:32 by kkeskin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_decidetype(char c, va_list args)
{
	int	chars;

	chars = 0;
	if (c == 'c')
		chars += ft_putchar(va_arg(args, int));
	else if (c == 's')
		chars += ft_putstr(va_arg(args, char *));
	else if (c == 'i' || c == 'd')
		chars += ft_putnbr(va_arg(args, int));
	else if (c == 'p')
		chars += ft_putadress(va_arg(args, void *));
	else if (c == 'x')
		chars += ft_puthexalow(va_arg(args, unsigned int));
	else if (c == 'X')
		chars += ft_puthexaup(va_arg(args, unsigned int));
	else if (c == 'u')
		chars += ft_putunsdecim(va_arg(args, unsigned int));
	else if (c == '%')
		chars += ft_putchar('%');
	return (chars);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		i;
	int		chars;

	i = 0;
	chars = 0;
	va_start(args, s);
	while (s[i])
	{
		if (s[i] == '%')
			chars += ft_decidetype(s[++i], args);
		else
			chars += ft_putchar(s[i]);
		i++;
	}
	va_end(args);
	return (chars);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexalow.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkeskin <kkeskin@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 13:00:02 by kkeskin           #+#    #+#             */
/*   Updated: 2025/06/18 13:00:03 by kkeskin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_solid_hexalow(unsigned int i, int *chars)
{
	if (i > 15)
		ft_solid_hexalow(i / 16, chars);
	*chars += ft_putchar(HEXA_LOWER[i % 16]);
}

int	ft_puthexalow(unsigned int i)
{
	int	chars;

	chars = 0;
	ft_solid_hexalow(i, &chars);
	return (chars);
}

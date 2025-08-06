/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsdecim.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkeskin <kkeskin@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 13:00:34 by kkeskin           #+#    #+#             */
/*   Updated: 2025/06/18 13:00:35 by kkeskin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_solid_unsdecim(unsigned int i, int *chars)
{
	if (i > 9)
		ft_solid_unsdecim(i / 10, chars);
	*chars += ft_putchar(DECIMAL[i % 10]);
}

int	ft_putunsdecim(unsigned int i)
{
	int	chars;

	chars = 0;
	ft_solid_unsdecim(i, &chars);
	return (chars);
}

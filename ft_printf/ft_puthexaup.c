/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexaup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkeskin <kkeskin@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 13:00:11 by kkeskin           #+#    #+#             */
/*   Updated: 2025/06/18 13:00:11 by kkeskin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_solid_hexaup(unsigned int i, int *chars)
{
	if (i > 15)
		ft_solid_hexaup(i / 16, chars);
	*chars += ft_putchar(HEXA_UPPER[i % 16]);
}

int	ft_puthexaup(unsigned int i)
{
	int	chars;

	chars = 0;
	ft_solid_hexaup(i, &chars);
	return (chars);
}

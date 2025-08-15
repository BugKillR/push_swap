/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkeskin <kkeskin@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 13:04:26 by kkeskin           #+#    #+#             */
/*   Updated: 2025/08/15 13:04:30 by kkeskin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "push_swap.h"

int	atoi_limits(const char *str, int *out)
{
	long	num;
	int		sign;

	num = 0;
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	if (!(*str >= '0' && *str <= '9'))
		return (0);
	while (*str >= '0' && *str <= '9')
	{
		num = num * 10 + (*str - '0');
		if ((sign == 1 && num > INT_MAX) || (sign == -1 && -(num) < INT_MIN))
			return (0);
		str++;
	}
	*out = (int)(num * sign);
	return (1);
}

int	sort_mid(t_greedy **a, t_greedy **b)
{
	int	i;

	(void)b;
	i = lstsize(*a);
	if (i == 3)
		return (sort_three(a), 1);
	else if (i == 4)
		return (sort_four(a, b), 1);
	else if (i == 5)
		return (sort_five(a, b), 1);
	return (0);
}

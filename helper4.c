/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkeskin <kkeskin@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 20:35:58 by kkeskin           #+#    #+#             */
/*   Updated: 2025/08/15 20:35:59 by kkeskin          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "push_swap.h"

static void	move_min_top(t_greedy **a)
{
	int	size;
	int	min_pos;
	int	k;

	size = lstsize(*a);
	if (size < 2)
		return ;
	min_pos = findmin(*a);
	if (min_pos <= size / 2)
	{
		k = min_pos;
		while (k--)
			ra(a, 1);
	}
	else
	{
		k = size - min_pos;
		while (k--)
			rra(a, 1);
	}
}

void	sort_three(t_greedy **a)
{
	int	x;
	int	y;
	int	z;

	x = (*a)->value;
	y = (*a)->next->value;
	z = (*a)->next->next->value;
	if (x < y && y < z)
		return ;
	if (x > y && y < z && x < z)
		return (sa(a, 1));
	else if (x > y && y > z)
		return (sa(a, 1), rra(a, 1));
	else if (x > y && y < z && x > z)
		return (ra(a, 1));
	else if (x < y && y > z && x < z)
		return (sa(a, 1), ra(a, 1));
	else if (x < y && y > z && x > z)
		return (rra(a, 1));
}

void	sort_four(t_greedy **a, t_greedy **b)
{
	move_min_top(a);
	pb(b, a, 1);
	sort_three(a);
	pa(a, b, 1);
}

void	sort_five(t_greedy **a, t_greedy **b)
{
	move_min_top(a);
	pb(b, a, 1);
	move_min_top(a);
	pb(b, a, 1);
	sort_three(a);
	pa(a, b, 1);
	pa(a, b, 1);
}

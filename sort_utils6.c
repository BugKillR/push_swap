/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils6.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkeskin <kkeskin@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 21:32:01 by kkeskin           #+#    #+#             */
/*   Updated: 2025/08/14 21:32:03 by kkeskin          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	operate_rx_rrx(t_greedy **a, t_greedy **b, t_greedy *c)
{
	int			abs_cost_a;
	int			abs_cost_b;

	abs_cost_a = ft_abs(c->cost_a);
	abs_cost_b = ft_abs(c->cost_b);
	if (c->cost_a >= 0)
	{
		while (abs_cost_a--)
			ra(a, 1);
	}
	else
	{
		while (abs_cost_a--)
			rra(a, 1);
	}
	if (c->cost_b >= 0)
	{
		while (abs_cost_b--)
			rb(b, 1);
	}
	else
	{
		while (abs_cost_b--)
			rrb(b, 1);
	}
}

void	execute_operations(t_greedy **a, t_greedy **b, t_greedy *cheapest)
{
	t_greedy	*c;

	c = cheapest;
	if ((c->cost_a >= 0 && c->cost_b >= 0)
		|| (c->cost_a < 0 && c->cost_b < 0))
	{
		if_rr_or_rrr(a, b, c);
		pb(b, a, 1);
	}
	else
	{
		operate_rx_rrx(a, b, c);
		pb(b, a, 1);
	}
}

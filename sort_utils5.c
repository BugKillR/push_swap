/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils5.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkeskin <kkeskin@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 20:35:25 by kkeskin           #+#    #+#             */
/*   Updated: 2025/08/14 20:35:25 by kkeskin          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	if_rr_a_bigger(t_greedy **a, t_greedy **b, t_greedy *c)
{
	int	execboth;
	int	execonly;

	execboth = ft_abs(c->cost_b);
	execonly = ft_abs(c->cost_a) - ft_abs(c->cost_b);
	while (execboth--)
		rr(a, b, 1);
	while (execonly--)
		ra(a, 1);
}

static void	if_rr_b_bigger(t_greedy **a, t_greedy **b, t_greedy *c)
{
	int	execboth;
	int	execonly;

	execboth = ft_abs(c->cost_a);
	execonly = ft_abs(c->cost_b) - ft_abs(c->cost_a);
	while (execboth--)
		rr(a, b, 1);
	while (execonly--)
		rb(b, 1);
}

static void	if_rrr_a_bigger(t_greedy **a, t_greedy **b, t_greedy *c)
{
	int	execboth;
	int	execonly;

	execboth = ft_abs(c->cost_b);
	execonly = ft_abs(c->cost_a) - ft_abs(c->cost_b);
	while (execboth--)
		rrr(a, b, 1);
	while (execonly--)
		rra(a, 1);
}

static void	if_rrr_b_bigger(t_greedy **a, t_greedy **b, t_greedy *c)
{
	int	execboth;
	int	execonly;

	execboth = ft_abs(c->cost_a);
	execonly = ft_abs(c->cost_b) - ft_abs(c->cost_a);
	while (execboth--)
		rrr(a, b, 1);
	while (execonly--)
		rrb(b, 1);
}

void	if_rr_or_rrr(t_greedy **a, t_greedy **b, t_greedy *c)
{
	if (c->cost_a >= 0 && c->cost_b >= 0)
	{
		if (ft_abs(c->cost_a) > ft_abs(c->cost_b))
			if_rr_a_bigger(a, b, c);
		else
			if_rr_b_bigger(a, b, c);
	}
	else if (c->cost_a < 0 && c->cost_b < 0)
	{
		if (ft_abs(c->cost_a) > ft_abs(c->cost_b))
			if_rrr_a_bigger(a, b, c);
		else
			if_rrr_b_bigger(a, b, c);
	}
}

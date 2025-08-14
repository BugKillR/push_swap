/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkeskin <kkeskin@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 20:03:16 by kkeskin           #+#    #+#             */
/*   Updated: 2025/08/14 20:03:17 by kkeskin          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_greedy	*find_by_index_b(t_greedy *b, int i)
{
	if (!b)
		return (NULL);
	while (b)
	{
		if (b->pos_b != i)
			b = b->next;
		else
			break ;
	}
	return (b);
}

static void	set_totalcost(t_greedy *a)
{
	if ((a->cost_a >= 0 && a->cost_b >= 0)
		|| (a->cost_a < 0 && a->cost_b < 0))
	{
		if (ft_abs(a->cost_a) > ft_abs(a->cost_b))
			a->totalcost = ft_abs(a->cost_a);
		else
			a->totalcost = ft_abs(a->cost_b);
	}
	else
		a->totalcost = ft_abs(a->cost_a) + ft_abs(a->cost_b);
}

void	set_cost(t_greedy *a, t_greedy *b)
{
	int	size_a;
	int	size_b;

	size_a = lstsize(a);
	size_b = lstsize(b);
	while (a)
	{
		if (a->pos_a <= size_a / 2)
			a->cost_a = a->pos_a;
		else
			a->cost_a = -(size_a - a->pos_a);
		if (a->target_pos_b <= size_b / 2)
			a->cost_b = a->target_pos_b;
		else
			a->cost_b = -(size_b - a->target_pos_b);
		set_totalcost(a);
		a = a->next;
	}
}

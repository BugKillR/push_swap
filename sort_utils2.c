/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkeskin <kkeskin@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 20:02:59 by kkeskin           #+#    #+#             */
/*   Updated: 2025/08/14 20:03:05 by kkeskin          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "push_swap.h"

t_greedy	*find_cheapest(t_greedy *s)
{
	t_greedy	*cheapest;

	if (!s)
		return (NULL);
	cheapest = s;
	while (s)
	{
		if (s->totalcost < cheapest->totalcost)
			cheapest = s;
		s = s->next;
	}
	return (cheapest);
}

void	reorder_b(t_greedy **stack_b)
{
	t_greedy	*max;
	int			size;
	int			steps;

	set_pos(NULL, *stack_b);
	max = find_by_index_b(*stack_b, findmax(*stack_b));
	size = lstsize(*stack_b);
	if (max->pos_b <= size / 2)
	{
		steps = max->pos_b;
		while (steps--)
			rb(stack_b, 1);
	}
	else
	{
		steps = size - max->pos_b;
		while (steps--)
			rrb(stack_b, 1);
	}
}

void	push_first_two(t_greedy **a, t_greedy **b)
{
	pb(b, a);
	pb(b, a);
	if ((*b)->index < (*b)->next->index)
		rb(b, 1);
}

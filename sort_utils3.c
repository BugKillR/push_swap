/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkeskin <kkeskin@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 20:03:09 by kkeskin           #+#    #+#             */
/*   Updated: 2025/08/14 20:03:10 by kkeskin          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "./ft_printf/ft_printf.h"
#include "push_swap.h"

void	reload_data(t_greedy **stack_a, t_greedy **stack_b)
{
	set_pos(*stack_a, *stack_b);
	set_target_pos_b(*stack_a, *stack_b);
	set_cost(*stack_a, *stack_b);
}

void	set_pos(t_greedy *stack_a, t_greedy *stack_b)
{
	int	pos;

	pos = 0;
	while (stack_a)
	{
		stack_a->pos_a = pos++;
		stack_a = stack_a->next;
	}
	pos = 0;
	while (stack_b)
	{
		stack_b->pos_b = pos++;
		stack_b = stack_b->next;
	}
}

static void	target_pos_b_helper(t_greedy *a, t_greedy *b)
{
	int			found;

	found = 0;
	while (b->next)
	{
		if (b->value >= a->value && a->value >= b->next->value)
		{
			a->target_pos_b = b->pos_b + 1;
			found = 1;
			break ;
		}
		b = b->next;
	}
	if (!found)
		a->target_pos_b = 0;
}

void	set_target_pos_b(t_greedy *a, t_greedy *stack_b)
{
	t_greedy	*max;
	t_greedy	*min;
	int			size;

	size = lstsize(stack_b);
	max = find_by_index_b(stack_b, findmax(stack_b));
	min = find_by_index_b(stack_b, findmin(stack_b));
	while (a)
	{
		if (max->value < a->value)
			a->target_pos_b = max->pos_b;
		else if (min->value > a->value)
		{
			if (min->pos_b == size - 1)
				a->target_pos_b = 0;
			else
				a->target_pos_b = min->pos_b + 1;
		}
		else
			target_pos_b_helper(a, stack_b);
		a = a->next;
	}
}

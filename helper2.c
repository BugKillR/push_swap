/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkeskin <kkeskin@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 20:20:08 by kkeskin           #+#    #+#             */
/*   Updated: 2025/08/14 20:20:08 by kkeskin          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "push_swap.h"

void	push_all_to_a(t_greedy **a, t_greedy **b)
{
	while (*b)
		pa(a, b, 1);
}

void	push_all_to_b(t_greedy **a, t_greedy **b)
{
	t_greedy	*cheapest;

	while (*a)
	{
		reload_data(a, b);
		cheapest = find_cheapest(*a);
		execute_operations(a, b, cheapest);
	}
}

int	sort_small(t_greedy **a, t_greedy **b)
{
	int	stack_size;

	stack_size = lstsize(*a);
	if (!*a || !a)
		return (ft_printf("Error\n"), 1);
	if (stack_size == 1)
	{
		return (clear_stacks(a, NULL), 1);
	}
	else if (stack_size == 2)
	{
		if ((*a)->value > (*a)->next->value)
			ra(a, 1);
		return (clear_stacks(a, NULL), 1);
	}
	else if (stack_size < 6)
	{
		if (sort_mid(a, b))
			return (clear_stacks(a, b), 1);
	}
	return (0);
}

void	clear_stacks(t_greedy **stack_a, t_greedy **stack_b)
{
	if (stack_a)
		lstclear(stack_a, free);
	if (stack_b)
		lstclear(stack_b, free);
}

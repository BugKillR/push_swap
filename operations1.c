/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkeskin <kkeskin@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 19:49:08 by kkeskin           #+#    #+#             */
/*   Updated: 2025/08/14 19:49:09 by kkeskin          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf/ft_printf.h"
#include "push_swap.h"

void	sa(t_greedy **stack_a, int print)
{
	int	value;

	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return ;
	value = (*stack_a)->value;
	(*stack_a)->value = (*stack_a)->next->value;
	(*stack_a)->next->value = value;
	if (print)
		ft_printf("sa\n");
}

void	sb(t_greedy **stack_b, int print)
{
	int	value;

	if (!stack_b || !*stack_b || !(*stack_b)->next)
		return ;
	value = (*stack_b)->value;
	(*stack_b)->value = (*stack_b)->next->value;
	(*stack_b)->next->value = value;
	if (print)
		ft_printf("sb\n");
}

void	ss(t_greedy **stack_a, t_greedy **stack_b, int p)
{
	sa(stack_a, 0);
	sb(stack_b, 0);
	if (p)
		ft_printf("ss\n");
}

void	pa(t_greedy **stack_a, t_greedy **stack_b, int print)
{
	t_greedy	*stack_b_next;

	if (!stack_b || !*stack_b)
		return ;
	stack_b_next = (*stack_b)->next;
	lstadd_front(stack_a, *stack_b);
	*stack_b = stack_b_next;
	if (print)
		ft_printf("pa\n");
}

void	pb(t_greedy **stack_b, t_greedy **stack_a, int print)
{
	t_greedy	*stack_a_next;

	if (!stack_a || !*stack_a)
		return ;
	stack_a_next = (*stack_a)->next;
	lstadd_front(stack_b, *stack_a);
	*stack_a = stack_a_next;
	if (print)
		ft_printf("pb\n");
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkeskin <kkeskin@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 19:50:18 by kkeskin           #+#    #+#             */
/*   Updated: 2025/08/14 19:50:18 by kkeskin          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf/ft_printf.h"
#include "push_swap.h"

void	ra(t_greedy **stack_a, int canprint)
{
	t_greedy	*first;
	t_greedy	*last;

	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return ;
	first = *stack_a;
	*stack_a = first->next;
	first->next = NULL;
	last = lstlast(*stack_a);
	last->next = first;
	if (canprint)
		ft_printf("ra\n");
}

void	rb(t_greedy **stack_b, int canprint)
{
	t_greedy	*first;
	t_greedy	*last;

	if (!stack_b || !*stack_b || !(*stack_b)->next)
		return ;
	first = *stack_b;
	*stack_b = first->next;
	first->next = NULL;
	last = lstlast(*stack_b);
	last->next = first;
	if (canprint)
		ft_printf("rb\n");
}

void	rr(t_greedy **stack_a, t_greedy **stack_b)
{
	ra(stack_a, 0);
	rb(stack_b, 0);
	ft_printf("rr\n");
}

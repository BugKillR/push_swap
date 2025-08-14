/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkeskin <kkeskin@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 19:50:49 by kkeskin           #+#    #+#             */
/*   Updated: 2025/08/14 19:50:50 by kkeskin          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf/ft_printf.h"
#include "push_swap.h"

void	rra(t_greedy **stack_a, int canprint)
{
	t_greedy	*last;
	t_greedy	*prev;

	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return ;
	prev = *stack_a;
	while (prev->next && prev->next->next)
		prev = prev->next;
	last = lstlast(*stack_a);
	prev->next = NULL;
	lstadd_front(stack_a, last);
	if (canprint)
		ft_printf("rra\n");
}

void	rrb(t_greedy **stack_b, int canprint)
{
	t_greedy	*last;
	t_greedy	*prev;

	if (!stack_b || !*stack_b || !(*stack_b)->next)
		return ;
	prev = *stack_b;
	while (prev->next && prev->next->next)
		prev = prev->next;
	last = lstlast(*stack_b);
	prev->next = NULL;
	lstadd_front(stack_b, last);
	if (canprint)
		ft_printf("rrb\n");
}

void	rrr(t_greedy **stack_a, t_greedy **stack_b)
{
	rra(stack_a, 0);
	rrb(stack_b, 0);
	ft_printf("rrr\n");
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkeskin <kkeskin@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 19:48:06 by kkeskin           #+#    #+#             */
/*   Updated: 2025/08/14 19:48:07 by kkeskin          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_greedy	*stack_a;
	t_greedy	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (1);
	argv++;
	if (!insert_elements(&stack_a, argv))
		return (clear_stacks(&stack_a, &stack_b), 1);
	if (is_sorted(stack_a))
		return (clear_stacks(&stack_a, &stack_b), 1);
	if (sort_small(&stack_a, &stack_b))
		return (0);
	setrank(&stack_a);
	push_first_two(&stack_a, &stack_b);
	push_all_to_b(&stack_a, &stack_b);
	reorder_b(&stack_b);
	push_all_to_a(&stack_a, &stack_b);
	clear_stacks(&stack_a, &stack_b);
	return (0);
}

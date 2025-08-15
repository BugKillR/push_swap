/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkeskin <kkeskin@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 02:45:12 by kkeskin           #+#    #+#             */
/*   Updated: 2025/08/15 02:45:13 by kkeskin          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	is_sorted(t_greedy *stack)
{
	if (!stack)
		return (0);
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

static int	apply_op(t_greedy **a, t_greedy **b, const char *s)
{
	if (!ft_strncmp(s, "rra", 3))
		return (rra(a, 0), 1);
	else if (!ft_strncmp(s, "rrb", 3))
		return (rrb(b, 0), 1);
	else if (!ft_strncmp(s, "rrr", 3))
		return (rrr(a, b, 0), 1);
	else if (!ft_strncmp(s, "pa", 2))
		return (pa(a, b, 0), 1);
	else if (!ft_strncmp(s, "pb", 2))
		return (pb(b, a, 0), 1);
	else if (!ft_strncmp(s, "ra", 2))
		return (ra(a, 0), 1);
	else if (!ft_strncmp(s, "rb", 2))
		return (rb(b, 0), 1);
	else if (!ft_strncmp(s, "rr", 2))
		return (rr(a, b, 0), 1);
	return (0);
}

static void	read_stdin(t_greedy **a, t_greedy **b)
{
	char	*read;

	read = get_next_line(0);
	while (read)
	{
		if (*read)
		{
			if (!apply_op(&a, &b, read))
			{
				free(read);
				lstclear(&a, free);
				lstclear(&b, free);
				ft_printf("Error\n");
				return (1);
			}
		}
		free(read);
		read = get_next_line(0);
	}
}

int	main(int argc, char **argv)
{
	t_greedy	*a;
	t_greedy	*b;

	a = NULL;
	b = NULL;
	if (argc < 2)
		return (0);
	if (!insert_elements_checker(&a, argv + 1))
		return (1);
	read_stdin(&a, &b);
	if (is_sorted(a) && !b)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	clear_stacks(&a, &b);
	return (0);
}

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

#include "../push_swap.h"
#include "../ft_printf/ft_printf.h"
#include "../libft/libft.h"
#include "../get_next_line/get_next_line.h"

static int	apply_op(t_greedy **a, t_greedy **b, const char *s)
{
	if (!ft_strncmp(s, "rra", 3) && ft_strlen(s) == 4)
		return (rra(a, 0), 1);
	else if (!ft_strncmp(s, "rrb", 3) && ft_strlen(s) == 4)
		return (rrb(b, 0), 1);
	else if (!ft_strncmp(s, "rrr", 3) && ft_strlen(s) == 4)
		return (rrr(a, b, 0), 1);
	else if (!ft_strncmp(s, "pa", 2) && ft_strlen(s) == 3)
		return (pa(a, b, 0), 1);
	else if (!ft_strncmp(s, "pb", 2) && ft_strlen(s) == 3)
		return (pb(b, a, 0), 1);
	else if (!ft_strncmp(s, "ra", 2) && ft_strlen(s) == 3)
		return (ra(a, 0), 1);
	else if (!ft_strncmp(s, "rb", 2) && ft_strlen(s) == 3)
		return (rb(b, 0), 1);
	else if (!ft_strncmp(s, "rr", 2) && ft_strlen(s) == 3)
		return (rr(a, b, 0), 1);
	else if (!ft_strncmp(s, "sa", 2) && ft_strlen(s) == 3)
		return (sa(a, 0), 1);
	else if (!ft_strncmp(s, "sb", 2) && ft_strlen(s) == 3)
		return (sb(b, 0), 1);
	else if (!ft_strncmp(s, "ss", 2) && ft_strlen(s) == 3)
		return (ss(a, b, 0), 1);
	return (0);
}

static int	read_stdin(t_greedy **a, t_greedy **b)
{
	char	*read;

	read = get_next_line(0);
	while (read)
	{
		if (*read)
		{
			if (!apply_op(a, b, read))
			{
				free(read);
				lstclear(a, free);
				lstclear(b, free);
				ft_printf("Error\n");
				return (1);
			}
		}
		free(read);
		read = get_next_line(0);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_greedy	*a;
	t_greedy	*b;

	a = NULL;
	b = NULL;
	if (argc < 2)
		return (0);
	if (!insert_elements(&a, argv + 1))
		return (clear_stacks(&a, &b), 1);
	if (read_stdin(&a, &b))
		return (clear_stacks(&a, &b), 1);
	if (is_sorted(a) && !b)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	return (clear_stacks(&a, &b), 0);
}

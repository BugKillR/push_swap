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

void	set_target_pos_b(t_greedy *a, t_greedy *stack_b)
{
	t_greedy	*b;
	int			pos;

	while (a)
	{
		pos = 0;
		b = stack_b;
		while (b)
		{
			if (b->index > a->index)
			{
				b = b->next;
				pos++;
			}
			else
				break ;
		}
		a->target_pos_b = pos;
		a = a->next;
	}
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

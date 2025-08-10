#include "./libft/libft.h"
#include "./ft_printf/ft_printf.h"
#include "push_swap.h"

void	reload_data(t_greedy **stack_a, t_greedy **stack_b)
{
	set_pos(stack_a, stack_b);
	set_target_pos_b(stack_a, *stack_b);
}

void	set_target_pos_b(t_greedy **stack_a, t_greedy *stack_b)
{
	t_greedy	*a;
	t_greedy	*b;
	int			pos;

	a = *stack_a;
	while (a)
	{
		pos = 0;
		b = stack_b;
		while (b)
		{
			if (a->index > b->index)
				break;
			else
			{
				pos++;
				b = b->next;
			}
		}
		a->target_pos_b = pos;
		a = a->next;
	}
}

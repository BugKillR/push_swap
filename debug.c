#include "./ft_printf/ft_printf.h"
#include "./libft/libft.h"
#include "push_swap.h"

void	print_stacks(t_greedy *stack_a, t_greedy *stack_b)
{
	ft_printf("\nStack A: ");
	while (stack_a)
	{
		ft_printf("%d ", stack_a->value);
		stack_a = stack_a->next;
	}
	ft_printf("\n");
	ft_printf("Stack B: ");
	while (stack_b)
	{
		ft_printf("%d ", stack_b->value);
		stack_b = stack_b->next;
	}
	ft_printf("\n\n");
}

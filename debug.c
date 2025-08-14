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

void	print_struct(t_greedy *stack_a, t_greedy *stack_b)
{
	t_greedy	*temp;

	temp = stack_a;
	while (temp)
	{
		ft_printf("\n\nContent: %d\nRank: %d\nPos_a: %d\nPos_b: %d\nPos_target_b: %d\nCost_a: %d\nCost_b: %d\nTotalCost: %d\n", temp->value, temp->index, temp->pos_a, temp->pos_b, temp->target_pos_b, temp->cost_a, temp->cost_b, temp->totalcost);
		temp = temp->next;
	}
	temp = stack_b;
	while (temp)
	{
		ft_printf("\n\nContent: %d\nRank: %d\nPos_a: %d\nPos_b: %d\nPos_target_b: %d\nCost_a: %d\nCost_b: %d\nTotalCost: %d\n", temp->value, temp->index, temp->pos_a, temp->pos_b, temp->target_pos_b, temp->cost_a, temp->cost_b, temp->totalcost);
		temp = temp->next;
	}
}
#include "./libft/libft.h"
#include "./ft_printf/ft_printf.h"
#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_greedy	*stack_a;
	t_greedy	*stack_b;

	if (argc < 2)
		return (1);
	argv++;
	if (!insert_elements(&stack_a, &stack_b, argv))
		return (1);
	setrank(&stack_a);
	print_stacks(stack_a, stack_b);
	set_pos_a(&stack_a, &stack_b);
	t_greedy	*temp;
	temp = stack_a;
	while (temp)
	{
		ft_printf("\n\nContent: %d\nRank: %d\nPos_a: %d\nPos_target_b: %d\nCost_a: %d\nCost_b: %d\nTotalCost: %d\n", temp->value, temp->index, temp->pos_a, temp->target_pos_b, temp->cost_a, temp->cost_b, temp->totalcost);
		temp = temp->next;
	}
	print_stacks(stack_a, stack_b);
	clear_stacks(&stack_a, &stack_b);
	return (0);
}

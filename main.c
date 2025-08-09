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
	if (!insertElements(&stack_a, &stack_b, argv))
		return (1);
	print_stacks(stack_a, stack_b);
	print_stacks(stack_a, stack_b);
	clear_stacks(&stack_a, &stack_b);
	return (0);
}

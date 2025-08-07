#include "./libft/libft.h"
#include "./ft_printf/ft_printf.h"
#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_list	*stack_a;
	t_list	*stack_b = NULL;

	if (argc < 2)
		return (1);
	argv++;
	if (!insertElements(&stack_a, argv))
		return (1);
	
	// Yazdırma testi

	pb(&stack_b, &stack_a);
	pb(&stack_b, &stack_a);
	print_stacks(stack_a, stack_b);

	if(stack_a)
		ft_lstclear(&stack_a, free);
	if(stack_b)
		ft_lstclear(&stack_b, free);
	return (0);
}

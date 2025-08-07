#include "./ft_printf/ft_printf.h"
#include "./libft/libft.h"

void    print_stacks(t_list *stack_a, t_list *stack_b)
{
    ft_printf("\nStack A: ");
    while (stack_a)
	{
		ft_printf("%d ", *(int *)stack_a->content);
		stack_a = stack_a->next;
	}
    ft_printf("\n");

    ft_printf("Stack B: ");
    while (stack_b)
	{
		ft_printf("%d ", *(int *)stack_b->content);
		stack_b = stack_b->next;
	}
    ft_printf("\n\n");
}
#include "./libft/libft.h"
#include "./ft_printf/ft_printf.h"
#include "push_swap.h"

void    FTwoElements(t_list **stack_a)
{
    if (*(int *)(*stack_a)->content > *(int *)(*stack_a)->next->content)
        ra(stack_a);
}

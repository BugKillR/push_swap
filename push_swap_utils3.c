#include "./libft/libft.h"
#include "./ft_printf/ft_printf.h"
#include "push_swap.h"

void	rra(t_list **stack_a)
{
	t_list	*last;
	t_list	*prev;

	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return ;
	prev = *stack_a;
	while (prev->next && prev->next->next)
		prev = prev->next;
	last = ft_lstlast(*stack_a);
	prev->next = NULL;
	ft_lstadd_front(stack_a, last);
	ft_printf("rra\n");
}

void	rrb(t_list **stack_b)
{
	t_list	*last;
	t_list	*prev;

	if (!stack_b || !*stack_b || !(*stack_b)->next)
		return ;
	prev = *stack_b;
	while (prev->next && prev->next->next)
		prev = prev->next;
	last = ft_lstlast(*stack_b);
	prev->next = NULL;
	ft_lstadd_front(stack_b, last);
	ft_printf("rrb\n");
}

void	rrr(t_list **stack_a, t_list **stack_b)
{
	rra(stack_a);
	rrb(stack_b);
	ft_printf("rrr\n");
}

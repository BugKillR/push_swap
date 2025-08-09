#include "./libft/libft.h"
#include "./ft_printf/ft_printf.h"
#include "push_swap.h"

void	rra(t_greedy **stack_a)
{
	t_greedy	*last;
	t_greedy	*prev;

	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return ;
	prev = *stack_a;
	while (prev->next && prev->next->next)
		prev = prev->next;
	last = lstlast(*stack_a);
	prev->next = NULL;
	lstadd_front(stack_a, last);
	ft_printf("rra\n");
}

void	rrb(t_greedy **stack_b)
{
	t_greedy	*last;
	t_greedy	*prev;

	if (!stack_b || !*stack_b || !(*stack_b)->next)
		return ;
	prev = *stack_b;
	while (prev->next && prev->next->next)
		prev = prev->next;
	last = lstlast(*stack_b);
	prev->next = NULL;
	lstadd_front(stack_b, last);
	ft_printf("rrb\n");
}

void	rrr(t_greedy **stack_a, t_greedy **stack_b)
{
	rra(stack_a);
	rrb(stack_b);
	ft_printf("rrr\n");
}

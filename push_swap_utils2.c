#include "./libft/libft.h"
#include "./ft_printf/ft_printf.h"
#include "push_swap.h"

void	ra(t_greedy **stack_a)
{
	t_greedy	*first;
	t_greedy	*last;

	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return ;
	first = *stack_a;
	*stack_a = first->next;
	first->next = NULL;
	last = lstlast(*stack_a);
	last->next = first;
	ft_printf("ra\n");
}

void	rb(t_greedy **stack_b)
{
	t_greedy	*first;
	t_greedy	*last;

	if (!stack_b || !*stack_b || !(*stack_b)->next)
		return ;
	first = *stack_b;
	*stack_b = first->next;
	first->next = NULL;
	last = lstlast(*stack_b);
	last->next = first;
	ft_printf("rb\n");
}

void	rr(t_greedy **stack_a, t_greedy **stack_b)
{
	ra(stack_a);
	rb(stack_b);
	ft_printf("rr\n");
}

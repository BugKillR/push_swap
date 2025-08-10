#include "./libft/libft.h"
#include "./ft_printf/ft_printf.h"
#include "push_swap.h"

void	sa(t_greedy **stack_a)
{
	int	value;

	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return ;
	value = (*stack_a)->value;
	(*stack_a)->value = (*stack_a)->next->value;
	(*stack_a)->next->value = value;
	ft_printf("sa\n");
}

void	sb(t_greedy **stack_b)
{
	int	value;

	if (!stack_b || !*stack_b || !(*stack_b)->next)
		return ;
	value = (*stack_b)->value;
	(*stack_b)->value = (*stack_b)->next->value;
	(*stack_b)->next->value = value;
	ft_printf("sb\n");
}

void	ss(t_greedy **stack_a, t_greedy **stack_b)
{
	sa(stack_a);
	sb(stack_b);
	ft_printf("ss\n");
}

void	pa(t_greedy **stack_a, t_greedy **stack_b)
{
	t_greedy	*stack_b_next;

	if (!stack_b || !*stack_b)
		return ;
	stack_b_next = (*stack_b)->next;
	lstadd_front(stack_a, *stack_b);
	*stack_b = stack_b_next;
	ft_printf("pa\n");
}

void	pb(t_greedy **stack_b, t_greedy **stack_a)
{
	t_greedy	*stack_a_next;

	if (!stack_a || !*stack_a)
		return ;
	stack_a_next = (*stack_a)->next;
	lstadd_front(stack_b, *stack_a);
	*stack_a = stack_a_next;
	ft_printf("pb\n");
}

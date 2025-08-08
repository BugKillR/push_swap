#include "./libft/libft.h"
#include "./ft_printf/ft_printf.h"
#include "push_swap.h"

int	findmin(t_list *stack)
{
	int	min;
	int	index;
	int	k;

	min = *(int *)stack->content;
	stack = stack->next;
	index = 0;
	k = 1;
	while(stack)
	{
		if (min > *(int *)stack->content)
		{
			min = *(int *)stack->content;
			index = k;
		}
		stack = stack->next;
		k++;
	}
	return (index);
}

t_algorithm	sort(t_algorithm algorithm, t_list **stack_a, t_list **stack_b)
{
	(void)stack_b;
	if (algorithm == TwoElement)
	{
		FTwoElements(stack_a);
	}
	else if (algorithm == ThreeToFive)
	{
		ft_printf("ThreeToFive");
	}
	else if (algorithm == Insertion)
	{
		ft_printf("Insertion");
	}
	else if (algorithm == Greedy)
	{
		ft_printf("Greedy");
	}
	return (algorithm);
}
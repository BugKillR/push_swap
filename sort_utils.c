#include "./libft/libft.h"
#include "./ft_printf/ft_printf.h"
#include "push_swap.h"

int	findmin(t_greedy *stack)
{
	int	min;
	int	index;
	int	k;

	min = *(stack)->content;
	stack = stack->next;
	index = 0;
	k = 1;
	while(stack)
	{
		if (min > *(stack)->content)
		{
			min = *(stack)->content;
			index = k;
		}
		stack = stack->next;
		k++;
	}
	return (index);
}

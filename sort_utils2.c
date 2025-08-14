#include "./libft/libft.h"
#include "push_swap.h"

int	is_stack_sorted(t_greedy *stack)
{
	int	expected;

	if (!stack)
		return (-1);
	expected = stack->index;
	while (stack)
	{
		if (stack->index == expected)
		{
			stack = stack->next;
			expected++;
		}
		else
			return (0);
	}
	return (1);
}

/*
t_list	*find_cheapest(t_greedy *s)
{
	t_list	*cheapest;

	if (!s)
		return (NULL);
	cheapest = s;
	s = s->next;
	while ()
}
*/
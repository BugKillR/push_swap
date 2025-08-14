#include "./libft/libft.h"
#include "./ft_printf/ft_printf.h"
#include "push_swap.h"

int	findmin(t_greedy *stack)
{
	int	min;
	int	index;
	int	k;

	min = stack->value;
	stack = stack->next;
	index = 0;
	k = 1;
	while (stack)
	{
		if (min > stack->value)
		{
			min = stack->value;
			index = k;
		}
		stack = stack->next;
		k++;
	}
	return (index);
}

static int	find_next_min_above(t_greedy *head, int last_min)
{
	t_greedy	*temp;
	int			curmin;
	
	curmin = 2147483647;
	temp = head;
	while (temp)
	{
		if (temp->value > last_min && temp->value < curmin)
		curmin = temp->value;
		temp = temp->next;
	}
	return (curmin);
}

static void	assign_index_for_value(t_greedy *head, int val, int *idx, int *last_min)
{
	t_greedy	*temp;
	
	temp = head;
	while (temp)
	{
		if (temp->value == val)
		{
			temp->index = (*idx)++;
			*last_min = val;
			return ;
		}
		temp = temp->next;
	}
}

void	setrank(t_greedy **stack_a)
{
	t_greedy	*head;
	int			stacksize;
	int			index;
	int			last_min;
	int			curmin;

	if (!stack_a || !*stack_a)
		return ;
	head = *stack_a;
	stacksize = lstsize(head);
	index = 0;
	last_min = -2147483648;
	while (index < stacksize)
	{
		curmin = find_next_min_above(head, last_min);
		if (curmin == 2147483647)
			break ;
		assign_index_for_value(head, curmin, &index, &last_min);
	}
}
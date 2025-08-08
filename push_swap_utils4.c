#include "./libft/libft.h"
#include "./ft_printf/ft_printf.h"
#include "push_swap.h"

int	insertElements(t_list **stack_a, t_list **stack_b, char **argv)
{
	int	*a;
	int	i;
	
	i = 0;
	*stack_a = NULL;
	*stack_b = NULL;
	while (argv[i])
	{
		if (!checkinput(argv[i]))
		{
			ft_printf("Error\n");
			ft_lstclear(stack_a, free);
			return (0);
		}
		a = malloc(sizeof(int));
		if (!a)
		{
			ft_lstclear(stack_a, free);
			return (0);
		}
		*a = ft_atoi(argv[i]);
		ft_lstadd_back(stack_a, ft_lstnew(a));
		i++;
	}
	return (1);
}

int	checkinput(char *str)
{
	int	i = 0;

	if (!str || !*str)
		return (0);
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

t_algorithm	decide_algorithm(t_list	*stack_a)
{
	int	stack_size;

	stack_size = ft_lstsize(stack_a);
	if (stack_size < 2)
		return (0);
	else if (stack_size == 2)
		return (1);
	else if (2 < stack_size && stack_size <= 5)
		return (2);
	else if (5 < stack_size && stack_size <= 100)
		return (3);
	else
		return (4);
}

void	clear_stacks(t_list **stack_a, t_list **stack_b)
{
	if (*stack_a)
		ft_lstclear(stack_a, free);
	if (*stack_b)
		ft_lstclear(stack_b, free);
}

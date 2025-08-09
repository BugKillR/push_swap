#include "./libft/libft.h"
#include "./ft_printf/ft_printf.h"
#include "push_swap.h"

int	insertElements(t_greedy **stack_a, t_greedy **stack_b, char **argv) // burada kaldın, lstnew'i t_greedy'e göre yeniden yaz
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
			lstclear(stack_a, free);
			return (0);
		}
		a = malloc(sizeof(int));
		if (!a)
		{
			lstclear(stack_a, free);
			return (0);
		}
		*a = ft_atoi(argv[i]);
		lstadd_back(stack_a, lstnew(a));
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

void	clear_stacks(t_greedy **stack_a, t_greedy **stack_b)
{
	if (*stack_a)
		lstclear(stack_a, free);
	if (*stack_b)
		lstclear(stack_b, free);
}

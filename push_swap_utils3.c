#include "./libft/libft.h"
#include "./ft_printf/ft_printf.h"
#include "./get_next_line/get_next_line.h"
#include "push_swap.h"

int	insertElements(t_list **stack_a, char **argv)
{
	int	*a;
	int	i;
	
	i = 0;
	*stack_a = NULL;
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

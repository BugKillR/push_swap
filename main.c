#include "./libft/libft.h"
#include "push_swap.h"
#include <stdio.h>

int	checkinput(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!('0' <= str[i] && str[i] <= '9'))
			return(0);
		i++;
	}
	return(1);
}

int main(int argc, char *argv[])
{
    t_list  *stackA = NULL;
    t_list  *stackB = NULL;
    t_list  *temp;
    int			i;

    if (argc < 2)
        return (1);
    i = 1;
    while (i < argc)
	{
		if (!stackA)
			stackA = ft_lstnew(ft_strdup(argv[i]));
		else
			ft_lstadd_back(&stackA, ft_lstnew(ft_strdup(argv[i])));
		i++;
	}

	printf("Old StackA: ");

	temp = stackA;
	while (temp)
	{
		printf("%s ", (char *)temp->content);
		temp = temp->next;
	}

	push(&stackB, &stackA);
	push(&stackB, &stackA);

	printf("\nNew StackA: ");

	temp = stackA;
	while (temp)
	{
		printf("%s ", (char *)temp->content);
		temp = temp->next;
	}

	printf("\n~~~ StackB: ");

	temp = stackB;
	while (temp)
	{
		printf("%s ", (char *)temp->content);
		temp = temp->next;
	}

	printf("\nNew StackA: ");

	rotate(&stackA);
	temp = stackA;
	while (temp)
	{
		printf("%s ", (char *)temp->content);
		temp = temp->next;
	}

	printf("\n");

	ft_lstclear(&stackA, free);
    ft_lstclear(&stackB, free);
	return (0);
}
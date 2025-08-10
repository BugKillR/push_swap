#include "push_swap.h"
#include "./libft/libft.h"

int	lstsize(t_greedy *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

t_greedy	*lstnew(int value)
{
	t_greedy	*head;

	head = (t_greedy *)malloc(sizeof(t_greedy));
	if (!head)
		return (NULL);
	head->value = value;
	head->next = NULL;
	return (head);
}

void	lstdelone(t_greedy *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	free(lst);
}

void	lstclear(t_greedy **lst, void (*del)(void *))
{
	t_greedy	*temp;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		temp = (*lst)->next;
		lstdelone(*lst, del);
		*lst = temp;
	}
}

void	lstadd_back(t_greedy **lst, t_greedy *new)
{
	t_greedy	*last;

	if (!lst || !new)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	last = lstlast(*lst);
	last->next = new;
}

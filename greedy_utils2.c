#include "push_swap.h"
#include "./libft/libft.h"

void	lstadd_front(t_greedy **lst, t_greedy *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}

t_greedy	*lstlast(t_greedy *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
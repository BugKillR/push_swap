#include "./libft/libft.h"
#include "push_swap.h"

void	rotate(t_list **lst)
{
	t_list	*first;
	t_list	*last;

	if (!lst || !*lst || !(*lst)->next)
		return ;
	first = *lst;
	*lst = first->next;
	first->next = NULL;
	last = ft_lstlast(*lst);
	last->next = first;
}

void	rotate_all(t_list **stackA, t_list **stackB)
{
	rotate(stackA);
	rotate(stackB);
}

void	reverse_rotate(t_list **lst)
{
	t_list	*last;
	t_list	*prev;

	if (!lst || !*lst || !(*lst)->next)
		return ;
	prev = *lst;
	while (prev->next && prev->next->next)
		prev = prev->next;
	prev->next = NULL;
	ft_lstadd_front(lst, last);
}

void	rr_all(t_list **stackA, t_list **stackB)
{
	reverse_rotate(stackA);
	reverse_rotate(stackB);
}

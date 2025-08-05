#include "./libft/libft.h"
#include "push_swap.h"

void	swap(t_list **lst)
{
	void	*content;

	if (!lst || !*lst || !(*lst)->next)
		return ;
	content = (*lst)->content;
	(*lst)->content = (*lst)->next->content;
	(*lst)->next->content = content;
}

void	swap_all(t_list **stackA, t_list **stackB)
{
	swap(stackA);
	swap(stackB);
}

void	push(t_list **target, t_list **package)
{
	t_list	*package_next;

	if (!package || !*package)
		return ;
	package_next = (*package)->next;
	ft_lstadd_front(target, *package);
	*package = package_next;
}

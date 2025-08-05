#include	"doubly_list.h"

d_list	*d_lstnew(void *content)
{
	d_list	*head;

	head = (d_list *)malloc(sizeof(d_list));
	if (!head)
		return (NULL);
	head->content = content;
	head->next = NULL;
	head->prev = NULL;
	return (head);
}

int	d_lstsize(d_list *lst)
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

void	d_lstadd_front(d_list **lst, d_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	if (*lst)
		(*lst)->prev = new;
	new->prev = NULL;
	*lst = new;
}
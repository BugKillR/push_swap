/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedy_list2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkeskin <kkeskin@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 19:45:41 by kkeskin           #+#    #+#             */
/*   Updated: 2025/08/14 19:45:42 by kkeskin          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

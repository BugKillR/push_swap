/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkeskin <kkeskin@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 02:44:54 by kkeskin           #+#    #+#             */
/*   Updated: 2025/08/15 02:44:55 by kkeskin          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	insert_elements_checker(t_greedy **a, char **argv)
{
	char	**arr;
	int		i;

	arr = makearr(argv);
	if (!arr)
		return (0);
	i = 0;
	while (arr[i])
	{
		if (!checkinput(arr[i]))
		{
			ft_printf("Error\n");
			free_double_arr(arr);
			lstclear(a, free);
			return (0);
		}
		lstadd_back(a, lstnew(ft_atoi(arr[i])));
		i++;
	}
	free_double_arr(arr);
	if (handle_clone_input(*a))
		return (ft_printf("Error\n"), 0);
	return (1);
}

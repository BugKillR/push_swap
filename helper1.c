/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkeskin <kkeskin@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 20:07:45 by kkeskin           #+#    #+#             */
/*   Updated: 2025/08/14 20:07:46 by kkeskin          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "./ft_printf/ft_printf.h"
#include "push_swap.h"

static char	**makearr(char **argv)
{
	char	**arr;
	char	*join;
	int		i;

	i = 0;
	join = NULL;
	while (argv[i])
	{
		ft_realloc(&join, argv[i]);
		ft_realloc(&join, " ");
		i++;
	}
	if (!join)
		return (NULL);
	arr = ft_split(join, ' ');
	free(join);
	return (arr);
}

static int	checkinput(char *str)
{
	int	i;

	i = 0;
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

static void	handle_convert_error(char **arr)
{
	int	k;

	k = 0;
	while (arr[k])
	{
		free(arr[k]);
		k++;
	}
	free(arr);
}

static int	handle_clone_input(t_greedy *a)
{
	t_greedy	*temp;
	int			curval;

	while (a)
	{
		curval = a->value;
		temp = a->next;
		while (temp)
		{
			if (curval == temp->value)
				return (1);
			temp = temp->next;
		}
		a = a->next;
	}
	return (0);
}

int	insert_elements(t_greedy **a, char **argv)
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
			handle_convert_error(arr);
			lstclear(a, free);
			return (0);
		}
		lstadd_back(a, lstnew(ft_atoi(arr[i])));
		i++;
	}
	handle_convert_error(arr);
	if (handle_clone_input(*a))
		return (ft_printf("Error\n"), 0);
	return (1);
}

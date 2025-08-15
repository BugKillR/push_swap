/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkeskin <kkeskin@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 20:34:11 by kkeskin           #+#    #+#             */
/*   Updated: 2025/08/14 20:34:11 by kkeskin          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "./libft/libft.h"
# include <fcntl.h>
# include <unistd.h>

typedef struct greedy_list
{
	int					value;
	int					index;

	int					pos_a;
	int					pos_b;
	int					target_pos_b;

	int					cost_a;
	int					cost_b;
	int					totalcost;

	struct greedy_list	*next;
}						t_greedy;

//	t_greedy functions

t_greedy	*lstnew(int value);
void		lstadd_front(t_greedy **lst, t_greedy *new);
int			lstsize(t_greedy *lst);
void		lstadd_back(t_greedy **lst, t_greedy *new);
void		lstdelone(t_greedy *lst, void (*del)(void *));
void		lstclear(t_greedy **lst, void (*del)(void *));
t_greedy	*lstlast(t_greedy *lst);

//	swap operations

void		sa(t_greedy **stack_a, int print);
void		sb(t_greedy **stack_b, int print);
void		ss(t_greedy **stack_a, t_greedy **stack_b, int p);

//  push operations

void		pa(t_greedy **stack_a, t_greedy **stack_b, int print);
void		pb(t_greedy **stack_b, t_greedy **stack_a, int print);

//  rotate operations

void		ra(t_greedy **stack_a, int canprint);
void		rb(t_greedy **stack_b, int canprint);
void		rr(t_greedy **stack_a, t_greedy **stack_b, int print);

//  reverse rotate operations

void		rra(t_greedy **stack_a, int canprint);
void		rrb(t_greedy **stack_b, int canprint);
void		rrr(t_greedy **stack_a, t_greedy **stack_b, int print);

//  helper functions

void		clear_stacks(t_greedy **stack_a, t_greedy **stack_b);
int			insert_elements(t_greedy **a, char **argv);
int			findmin(t_greedy *stack);
int			findmax(t_greedy *stack);
t_greedy	*find_by_index_b(t_greedy *b, int i);
char		**makearr(char **argv);
int			checkinput(char *str);
void		free_double_arr(char **arr);
int			handle_clone_input(t_greedy *a);
int			atoi_limits(const char *str, int *out);

//	sort (Reload Data, Push to B while sorting, Push back to a and reorder)

void		push_first_two(t_greedy **a, t_greedy **b);

void		reload_data(t_greedy **stack_a, t_greedy **stack_b);
void		setrank(t_greedy **stack_a);
void		set_pos(t_greedy *stack_a, t_greedy *stack_b);
void		set_target_pos_b(t_greedy *stack_a, t_greedy *stack_b);
void		set_cost(t_greedy *a, t_greedy *b);

void		push_all_to_b(t_greedy **a, t_greedy **b);
t_greedy	*find_cheapest(t_greedy *s);

void		execute_operations(t_greedy **a, t_greedy **b, t_greedy *cheapest);
void		if_rr_or_rrr(t_greedy **a, t_greedy **b, t_greedy *c);

void		push_all_to_a(t_greedy **a, t_greedy **b);
void		reorder_b(t_greedy **stack_b);

int			sort_small(t_greedy **a, t_greedy **b);
int			sort_mid(t_greedy **a, t_greedy **b);
void		sort_three(t_greedy **a);
void		sort_four(t_greedy **a, t_greedy **b);
void		sort_five(t_greedy **a, t_greedy **b);
int			is_sorted(t_greedy *stack);

#endif

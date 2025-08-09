#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "./libft/libft.h"
# include <fcntl.h>
# include <unistd.h>

typedef struct greedy_list
{
	int					*content;
	int					index;
	int					cost_a;
	int					cost_b;
	int					totalcost;
	struct greedy_list	*next;
}						t_greedy;

//	t_greedy functions

t_greedy	*lstnew(void *content);
void		lstadd_front(t_greedy **lst, t_greedy *new);
int			lstsize(t_greedy *lst);
void		lstadd_back(t_greedy **lst, t_greedy *new);
void		lstdelone(t_greedy *lst, void (*del)(void *));
void		lstclear(t_greedy **lst, void (*del)(void *));
t_greedy	*lstlast(t_greedy *lst);

//  swap operations

void	sa(t_greedy **stack_a);
void	sb(t_greedy **stack_b);
void	ss(t_greedy **stack_a, t_greedy **stack_b);

//  push operations

void	pa(t_greedy **stack_a, t_greedy **stack_b);
void	pb(t_greedy **stack_b, t_greedy **stack_a);

//  rotate operations

void	ra(t_greedy **stack_a);
void	rb(t_greedy **stack_b);
void	rr(t_greedy **stack_a, t_greedy **stack_b);

//  reverse rotate operations

void	rra(t_greedy **stack_a);
void	rrb(t_greedy **stack_b);
void	rrr(t_greedy **stack_a, t_greedy **stack_b);

//  other functions

void		clear_stacks(t_greedy **stack_a, t_greedy **stack_b);
int			insertElements(t_greedy **stack_a, t_greedy **stack_b, char **argv);
int			checkinput(char *str);
int			findmin(t_greedy *stack);

//	sort

//  helper funct (REMOVE LATER)

void	print_stacks(t_greedy *stack_a, t_greedy *stack_b);

#endif
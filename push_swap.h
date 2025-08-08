#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "./libft/libft.h"
# include <fcntl.h>
# include <unistd.h>

typedef enum e_algorithm {
	Empty,
	TwoElement,
	ThreeToFive,
	Insertion,
	Greedy
}	t_algorithm;

//  swap operations

void	sa(t_list **stack_a);
void	sb(t_list **stack_b);
void	ss(t_list **stack_a, t_list **stack_b);

//  push operations

void	pa(t_list **stack_a, t_list **stack_b);
void	pb(t_list **stack_b, t_list **stack_a);

//  rotate operations

void	ra(t_list **stack_a);
void	rb(t_list **stack_b);
void	rr(t_list **stack_a, t_list **stack_b);

//  reverse rotate operations

void	rra(t_list **stack_a);
void	rrb(t_list **stack_b);
void	rrr(t_list **stack_a, t_list **stack_b);

//  other functions

t_algorithm	decide_algorithm(t_list	*stack_a);
void		clear_stacks(t_list **stack_a, t_list **stack_b);
int			insertElements(t_list **stack_a, t_list **stack_b, char **argv);
int			checkinput(char *str);
int			findmin(t_list *stack);

//	sort

t_algorithm	sort(t_algorithm algorithm, t_list **stack_a, t_list **stack_b);
void    	FTwoElements(t_list **stack_a);

//  helper funct (REMOVE LATER)

void	print_stacks(t_list *stack_a, t_list *stack_b);

#endif
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "./libft/libft.h"
# include <fcntl.h>
# include <unistd.h>

void	swap_a(t_list **lst);
void	swap_all(t_list **stackA, t_list **stackB);
void	push(t_list **target, t_list **package);
void	rotate(t_list **lst);
void	rotate_all(t_list **stackA, t_list **stackB);
void	reverse_rotate(t_list **lst);
void	rr_all(t_list **stackA, t_list **stackB);

int	    insertElements(t_list **stack_a, char **argv);
int	    checkinput(char *str);

#endif
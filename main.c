#include "./libft/libft.h"
#include "./ft_printf/ft_printf.h"
#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_list	*stack_a;
	//t_list	*stack_b;

	if (argc < 2)
		return (1);
	argv++;
	if (!insertElements(&stack_a, argv))
		return (1);

	// Yazdırma testi

	t_list	*temp;
	temp = stack_a;
	while(temp)
	{
		ft_printf("%d\n", *(int *)temp->content);
		temp = temp->next;
	}

	// Yazdırma testi

	ft_lstclear(&stack_a, free);
	return (0);
}

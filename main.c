#include "./libft/libft.h"
#include "./ft_printf/ft_printf.h"
#include "./get_next_line/get_next_line.h"
#include "push_swap.h"
#include <stdio.h>

static int	checkinput(char *str, int fd)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '-' || str[i] == '+')
			write(fd, &str[i++], 1);
		if (!('0' <= str[i] && str[i] <= '9'))
			return (0);
		write(fd, &str[i++], 1);
	}
	write(fd, "\n", 1);
	return (1);
}

static void	insertelements(t_list **stackA, int fd)
{
	char	*read;
	int		*a;

	*stackA = NULL;
	fd_renew(fd);
	read = get_next_line(fd);
	if (!read)
		return ;
	while (read)
	{
		a = malloc(sizeof(int));
		if (!a)
		{
			ft_lstclear(stackA, free);
			return ;
		}
		*a = ft_atoi(read);
		ft_lstadd_back(stackA, ft_lstnew(a));
		free(read);
		read = get_next_line(fd);
	}
	fd_renew(fd);
}

int	main(int argc, char *argv[])
{
	t_list	*stack_a;
	//t_list	*stack_b;
	int		fd;

	if (argc < 2)
		return (1);
	fd = open("Data.txt", O_CREAT | O_RDWR | O_TRUNC, 0644);
	argv++;
	while (*argv)
	{
		if (!checkinput(*argv, fd))
		{
			ft_printf("Error\n");
			return (1);
		}
		argv++;
	}
	insertelements(&stack_a, fd); // Elemanlar listeye atılıyor ve integer'a çeviriliyor.

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

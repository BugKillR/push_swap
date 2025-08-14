NAME = push_swap.a

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

PRINTF_DIR = ./ft_printf
PRINTF = $(PRINTF_DIR)/libftprintf.a

SRCS = greedy_list1.c \
		greedy_list2.c \
		helper1.c \
		helper2.c \
		operations1.c \
		operations2.c \
		operations3.c \
		sort_utils1.c \
		sort_utils2.c \
		sort_utils3.c \
		sort_utils4.c \
		sort_utils5.c \
		sort_utils6.c

OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)
	$(CC) $(CFLAGS) -g main.c *.a -o push_swap

$(NAME): $(OBJS) $(LIBFT) $(PRINTF)
	ar rcs $(NAME) $(OBJS) ./libft/*.o ./ft_printf/*.o

$(LIBFT):
	make -C $(LIBFT_DIR) all

$(PRINTF):
	make -C $(PRINTF_DIR) all

clean:
	make -C $(LIBFT_DIR) clean
	make -C $(PRINTF_DIR) clean
	rm -rf $(OBJS)

fclean: clean
	make -C $(PRINTF_DIR) fclean
	make -C $(LIBFT_DIR) fclean
	rm -rf $(NAME) push_swap.a

re: fclean all

.PHONY: all clean fclean re libft
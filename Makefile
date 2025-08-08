NAME = push_swap.a

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

PRINTF_DIR = ./ft_printf
PRINTF = $(PRINTF_DIR)/libftprintf.a

SRCS = debug.c \
		push_swap_utils1.c \
		push_swap_utils2.c \
		push_swap_utils3.c \
		push_swap_utils4.c \
		sort_utils.c \
		TwoElements.c

OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)
	$(CC) -g $(CFLAGS) main.c *.a -o push_swap

$(NAME): $(OBJS) $(LIBFT) $(PRINTF)
	ar rcs $(NAME) $(OBJS) ./libft/*.o ./ft_printf/*.o

$(LIBFT):
	make -C $(LIBFT_DIR) bonus

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
NAME = push_swap.a
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

SRCS = push_swap.c \
		push_swap_utils.c
OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(LIBFT) $(NAME)
	$(CC) $(CFLAGS) main.c *.a -o push_swap

$(NAME): $(OBJS) $(LIBFT)
	ar rcs $(NAME) $(OBJS) ./libft/*.o

$(LIBFT):
	make -C $(LIBFT_DIR) bonus

clean:
	make -C $(LIBFT_DIR) clean
	rm -rf $(OBJS)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	rm -rf $(NAME) push_swap

re: fclean all

.PHONY: all clean fclean re libft
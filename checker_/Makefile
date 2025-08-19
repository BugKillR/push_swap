NAME	= checker.a

CC		= cc
CFLAGS	= -Wall -Wextra -Werror

LIBFT_DIR = ../libft
LIBFT = $(LIBFT_DIR)/libft.a

PRINTF_DIR = ../ft_printf
PRINTF = $(PRINTF_DIR)/ft_printf.a

PUSH_SWAP_DIR = ..
PUSH_SWAP = $(PUSH_SWAP_DIR)/push_swap.a

GNL_DIR = ../get_next_line
GNL = $(GNL_DIR)/get_next_line.a

all: $(NAME)
	$(CC) $(CFLAGS) main.c checker.a -o checker
	mv checker ..

$(NAME): $(LIBFT) $(PRINTF) $(PUSH_SWAP) $(GNL)
	ar rcs $(NAME) $(LIBFT_DIR)/*.o $(PRINTF_DIR)/*.o $(PUSH_SWAP_DIR)/*.o $(GNL_DIR)/*.o 

$(LIBFT):
	make -C $(LIBFT_DIR) all

$(PRINTF):
	make -C $(PRINTF_DIR) all

$(PUSH_SWAP):
	make -C $(PUSH_SWAP_DIR) all

$(GNL):
	make -C $(GNL_DIR) all

clean:
	make -C $(GNL_DIR) clean
	rm -rf $(GNL_OBJS)

fclean: clean
	make -C $(GNL_DIR) fclean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
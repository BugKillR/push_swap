NAME	= libft.a

CC		= cc
CFLAGS	= -Wall -Wextra -Werror

SRCS	= ft_atoi.c \
			ft_split.c \
			ft_strdup.c \
			ft_strjoin.c \
			ft_strlen.c \
			ft_substr.c \
			ft_abs.c \
			ft_realloc.c \
			ft_strncmp.c

OBJS	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS) $(BONUS_OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

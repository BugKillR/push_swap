NAME	=	libftprintf.a

CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror

SRCS	= 	ft_printf.c \
			ft_putchar.c \
			ft_putstr.c \
			ft_putnbr.c \
			ft_putadress.c \
			ft_puthexaup.c \
			ft_puthexalow.c \
			ft_putunsdecim.c

OBJS	=	$(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@ar -rcs $(NAME) $(OBJS)

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclear re
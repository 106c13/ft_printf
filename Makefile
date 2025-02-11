CC = gcc
CFLAGS = -Wall -Werror -Wextra
RM = rm -rf
AR = ar crs

NAME = libftprintf.a

SRC	=	ft_printf.c			\
		ft_printf_align.c	\
		ft_printf_char.c	\
		ft_printf_finders.c	\
		ft_printf_nbr.c		\
		ft_printf_utils.c	\
		ft_itoa.c			\
		ft_strlen.c			\
		ft_memcpy.c			\
		ft_memset.c			\
		ft_strdub.c

OBJS = $(SRC:.c=.o)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

bonus: $(OBJS)
	$(AR) $(NAME) $(OBJS)

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)		

re:	fclean all

.PHONY:	all clean fclean re

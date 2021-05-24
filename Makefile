NAME = libftprintf.a

CC = clang 

CFLAGS = -Wall -Wextra -Werror 

SRCS =	ft_flags.c \
		ft_print_char.c \
		ft_print_nb.c \
		ft_printf.c \
		ft_putchar.c \
		ft_print_string.c \
		ft_print_pointer.c \
		ft_print_modulo.c \
		ft_print_unsigned.c \
		ft_print_hex.c \
		ft_utils.c \
		ft_flags2.c

OBJS = ${SRCS:.c=.o}

all : $(NAME)

.c.o: 
		$(CC) $(CFLAGS) -c $< -o ${<:.c=.o}

$(NAME) : $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean : 
	rm -f $(OBJS)

fclean : clean 
	rm -f $(NAME)

re : fclean all

debug : $(NAME)
	$(CC) $(CFLAGS) main.c $(NAME)
	./a.out
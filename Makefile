NAME		=	libftprintf.a

LIBFT		=	libft.a

LIBFT_PATH	=	libft/

SRC			=	ft_printf.c

OBJ			=	$(SRC:.c=.o)

BONUS		=	

BONUS_OBJ	=	$(BONUS:.c=.o)

CFLAGS		=	-Wall -Wextra -Werror -I.

RM			=	rm -f

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	cp $(LIBFT_PATH)$(LIBFT) $(NAME)
	ar rcs $(NAME) $(OBJ)

$(LIBFT):
	make -C $(LIBFT_PATH)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

bonus:

clean:
	make -C $(LIBFT_PATH) clean
	$(RM) $(OBJ) $(BONUS_OBJ)

fclean: clean
	make -C $(LIBFT_PATH) fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

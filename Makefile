CC := cc

CFLAGS := -Wall -Wextra -Werror


SRCS := push_swap.c\
		stack_utils.c\
		stack_utils_2.c\
		sort.c\
		input_checks.c\
		push.c\
		rotate.c\
		rev_rotate.c\
		swap.c\
		stack_a.c\
		stack_b.c\

LIBFT = ./ft_printf/libftprintf.a

OBJS := $(SRCS:.c=.o)

NAME := push_swap

$(NAME): $(OBJS) $(LIBFT) 
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME) 
 
all: $(NAME) $(LIBFT) 

$(LIBFT):
	@make -C ./ft_printf
 
clean:
	@rm -f $(OBJS)
	@make clean -C ./ft_printf
	
fclean: clean
	@make fclean -C ./ft_printf
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

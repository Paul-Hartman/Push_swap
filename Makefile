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

BONUS_SRCS := ./bonus/checker.c\
		./bonus/get_next_line.c\
		stack_utils.c\
		stack_utils_2.c\
		sort.c\
		input_checks.c\
		push.c\
		rotate.c\
		rev_rotate.c\
		swap.c\

LIBFT = ./ft_printf/libftprintf.a


BONUS_OBJS := $(BONUS_SRCS:.c=.o)

OBJS := $(SRCS:.c=.o)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

NAME := push_swap

$(NAME): $(OBJS) $(LIBFT) 
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME) 
 
all: $(NAME) $(LIBFT)

bonus: $(BONUS_OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) $(BONUS_OBJS) $(LIBFT) -o checker

$(LIBFT):
	@make -C ./ft_printf
 
clean:
	@rm -f $(OBJS)
	@make clean -C ./ft_printf
	
fclean: clean
	@make fclean -C ./ft_printf
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus

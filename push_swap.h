/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phartman <phartman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 14:27:19 by phartman          #+#    #+#             */
/*   Updated: 2024/06/20 19:26:29 by phartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./ft_printf/ft_printf.h"
# include "./ft_printf/libft/libft.h"
# include <limits.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack_node
{
	int					nbr;
	int					index;
	int					push_cost;
	bool				above_median;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
	struct s_stack_node	*target;
}						t_stack_node;

int						print_error(char *msg);
t_stack_node			*handle_args(int argc, char const *argv[]);

// stack_utils.c
t_stack_node			*stack_max(t_stack_node *stk);
t_stack_node			*stack_min(t_stack_node *stk);
t_stack_node			*stack_last(t_stack_node *stk);
int						stack_len(t_stack_node *stk);
void					stack_add(t_stack_node **stk, int n);

// operations.c
int						push_a(t_stack_node **a, t_stack_node **b);
int						push_b(t_stack_node **a, t_stack_node **b);
int						rotate(t_stack_node **stack, bool reverse);
int						swap(t_stack_node **stack);

// operation_wrappers.c
int						swap_both(t_stack_node **a, t_stack_node **b);
int						rotate_both(t_stack_node **a, t_stack_node **b,
							int reverse);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phartman <phartman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 13:32:13 by phartman          #+#    #+#             */
/*   Updated: 2024/07/02 13:32:13 by phartman         ###   ########.fr       */
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
	int nbr;
	int index;
	int push_cost;
	bool above_median;
	bool cheapest;
	struct s_stack_node *next;
	struct s_stack_node *prev;
	struct s_stack_node *target;
} t_stack_node;





// stack_utils.c
t_stack_node	*stack_max(t_stack_node *stk);
t_stack_node	*stack_min(t_stack_node *stk);
t_stack_node	*stack_last(t_stack_node *stk);
int	stack_len(t_stack_node *stk);
void	stack_add(t_stack_node **stk, int n);
void free_stack(t_stack_node **stk);

// operations.c
int	push_a(t_stack_node **a, t_stack_node **b);
int	push_b(t_stack_node **a, t_stack_node **b);
int	rotate(t_stack_node **stack, bool reverse);
int	swap(t_stack_node **stack);

// operation_wrappers.c
int	ss(t_stack_node **a, t_stack_node **b);
int	rr(t_stack_node **a, t_stack_node **b);
int	rrr(t_stack_node **a, t_stack_node **b);
int	sa(t_stack_node **a);
int	sb(t_stack_node **b);
int	ra(t_stack_node **a);
int	rb(t_stack_node **b);
int	rra(t_stack_node **a);
int	rrb(t_stack_node **b);
int	pa(t_stack_node **a, t_stack_node **b);
int	pb(t_stack_node **a, t_stack_node **b);

// sort.c
int	sort_three(t_stack_node **a);
void	first_push(t_stack_node **a, t_stack_node **b, int len);
void	assign_target_b(t_stack_node *a, t_stack_node *b);
void	assign_target_a(t_stack_node *a, t_stack_node *b);
void	assign_indexes(t_stack_node *stack);
//int	find_push_cost(t_stack_node **a, t_stack_node **b);
void	is_above_median(t_stack_node **stack);
void	push_cheapest_a(t_stack_node **a, t_stack_node **b);
void	push_cheapest_b(t_stack_node **a, t_stack_node **b);
void min_to_top(t_stack_node **a);
void set_cheapest(t_stack_node *stack);
t_stack_node	*get_cheapest(t_stack_node *a);
void find_push_cost_b(t_stack_node *a, t_stack_node *b);
void find_push_cost_a(t_stack_node *a, t_stack_node *b);

void	push_cheapest(t_stack_node **a, t_stack_node **b, char stack);



int find_max(int a , int b);
int find_min(int a , int b);

//input_checks.c
bool	stack_sorted(t_stack_node *stack);
bool	all_digits(char *str);
int	check_dups(t_stack_node *stack, int num);
t_stack_node	*handle_args(int argc, char const *argv[]);
int	print_error(t_stack_node *stack);
#endif



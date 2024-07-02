/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+        
	+:+     */
/*   By: phartman <phartman@student.42.fr>          +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+  
	+#+           */
/*   Created: 2024/07/02 13:32:13 by phartman          #+#    #+#             */
/*   Updated: 2024/07/02 13:32:13 by phartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf/ft_printf.h"
# include "ft_printf/libft/libft.h"
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
	bool				cheapest;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
	struct s_stack_node	*target;
}	t_stack_node;

// stack_utils.c
t_stack_node	*stack_max(t_stack_node *stk);
t_stack_node	*stack_min(t_stack_node *stk);
t_stack_node	*stack_last(t_stack_node *stk);
t_stack_node	*get_cheapest(t_stack_node *a);
int				stack_len(t_stack_node *stk);

// stack_utils_2.c
void			assign_indexes(t_stack_node *stack);
void			is_above_median(t_stack_node *stack);
void			set_cheapest(t_stack_node *stack);
void			stack_add(t_stack_node **stk, int n);
void			free_stack(t_stack_node **stk);

// swap.c
void			swap(t_stack_node **stack);
void			ss(t_stack_node **a, t_stack_node **b);
void			sa(t_stack_node **a);
void			sb(t_stack_node **b);

// push.c
void			push_a(t_stack_node **a, t_stack_node **b);
void			push_b(t_stack_node **a, t_stack_node **b);
void			pa(t_stack_node **a, t_stack_node **b);
void			pb(t_stack_node **a, t_stack_node **b);

// rotate.c
void			rotate(t_stack_node **stack, bool reverse);
void			ra(t_stack_node **a);
void			rb(t_stack_node **b);
void			rr(t_stack_node **a, t_stack_node **b);

// rev_rotate.c
void			rrr(t_stack_node **a, t_stack_node **b);
void			rra(t_stack_node **a);
void			rrb(t_stack_node **b);

// stack_a.c
void			process_a(t_stack_node **stack_a, t_stack_node **stack_b);
void			assign_target_a(t_stack_node *a, t_stack_node *b);
void			find_push_cost_a(t_stack_node *a, t_stack_node *b);
void			rotate_to_top_a(t_stack_node **a, t_stack_node **b,
					t_stack_node *cheapest);
void			push_cheapest_a(t_stack_node **a, t_stack_node **b);

// stack_b.c
void			process_b(t_stack_node **stack_a, t_stack_node **stack_b);
void			assign_target_b(t_stack_node *a, t_stack_node *b);
void			find_push_cost_b(t_stack_node *a, t_stack_node *b);
void			rotate_to_top_b(t_stack_node **a, t_stack_node **b,
					t_stack_node *cheapest);
void			push_cheapest_b(t_stack_node **a, t_stack_node **b);

// sort.c
void			sort_three(t_stack_node **a);
void			sort_two(t_stack_node **a, int len);
void			min_to_top(t_stack_node **a);
void			first_push(t_stack_node **a, t_stack_node **b, int len);

// input_checks.c
bool			stack_sorted(t_stack_node *stack);
bool			all_digits(char *str);
int				check_dups(t_stack_node *stack, int num);
int				print_error(t_stack_node *stack);
t_stack_node	*handle_args(int argc, char const *argv[]);
#endif

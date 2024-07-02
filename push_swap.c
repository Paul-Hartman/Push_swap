/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phartman <phartman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 13:31:48 by phartman          #+#    #+#             */
/*   Updated: 2024/07/02 13:31:48 by phartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, const char *argv[])
{
	t_stack_node *stack_a;
	t_stack_node *stack_b;

	stack_b = NULL;
	if (argc < 2)
		return (print_error(NULL));
	else if (strlen(argv[1]) == 0)
		return (print_error(NULL));
	else
		stack_a = handle_args(argc, argv);
	if (stack_sorted(stack_a))
	{
		free_stack(&stack_a);
		return (0);
	}
	first_push(&stack_a, &stack_b, stack_len(stack_a));
	while (!stack_sorted(stack_a))
	{
		if (stack_len(stack_a) == 3)
		{
			sort_three(&stack_a);
			break ;
		}
		assign_indexes(stack_a);
		assign_indexes(stack_b);
		is_above_median(&stack_a);
		is_above_median(&stack_b);
		assign_target_a(stack_a, stack_b);
		find_push_cost_a(stack_a, stack_b);
		set_cheapest(stack_a);
		push_cheapest_a(&stack_a, &stack_b);
	}
	if (stack_len(stack_a) == 3)
	{
		sort_three(&stack_a);
	}
	while (stack_b)
	{
		assign_indexes(stack_a);
		assign_indexes(stack_b);
		is_above_median(&stack_a);
		is_above_median(&stack_b);
		assign_target_b(stack_a, stack_b);
		find_push_cost_b(stack_a, stack_b);
		set_cheapest(stack_b);
		push_cheapest_b(&stack_a, &stack_b);
	}
	min_to_top(&stack_a);
	free_stack(&stack_a);
	return (0);
}



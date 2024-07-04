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
	t_stack_node	*stack_a;
	t_stack_node	*stack_b;

	if (argc < 2)
		return (1);
	stack_b = NULL;
	stack_a = handle_args(argc, argv);
	sort_two(&stack_a, stack_len(stack_a));
	if (stack_sorted(stack_a))
	{
		free_stack(&stack_a);
		return (0);
	}
	first_push(&stack_a, &stack_b, stack_len(stack_a));
	while (stack_len(stack_a) > 3)
		process_a(&stack_a, &stack_b);
	sort_three(&stack_a);
	while (stack_b)
		process_b(&stack_a, &stack_b);
	min_to_top(&stack_a);
	free_stack(&stack_a);
	return (0);
}

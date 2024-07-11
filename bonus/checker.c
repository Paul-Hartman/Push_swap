/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phartman <phartman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 18:41:31 by phartman          #+#    #+#             */
/*   Updated: 2024/07/11 17:50:24 by phartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void run_op(char *op, t_stack_node **stack_a, t_stack_node **stack_b)
{
	if (ft_strncmp(op, "sa", 2) == 0)
		swap(stack_a);
	else if (ft_strncmp(op, "sb", 2) == 0)
		swap(stack_b);
	else if (ft_strncmp(op, "ss", 2) == 0)
	{
		swap(stack_a);
		swap(stack_b);
	}
	else if (ft_strncmp(op, "pa", 2) == 0)
		push_a(stack_a, stack_b);
	else if (ft_strncmp(op, "pb", 2) == 0)
		push_b(stack_a, stack_b);
	else if (ft_strncmp(op, "ra", 2) == 0)
		rotate(stack_a, false);
	else if (ft_strncmp(op, "rb", 2) == 0)
		rotate(stack_b, false);
	
	else if (ft_strncmp(op, "rra", 3) == 0)
		rotate(stack_a, true);
	else if (ft_strncmp(op, "rrb", 3) == 0)
		rotate(stack_b, true);
	else if (ft_strncmp(op, "rrr", 3) == 0)
	{
		rotate(stack_a, true);
		rotate(stack_b, true);
	}
	else if (ft_strncmp(op, "rr", 2) == 0)
	{
		rotate(stack_a, false);
		rotate(stack_b, false);
	}
	else
	{
		if(stack_b)
			free_stack(stack_b);
		free(op);
		print_error(*stack_a);
		exit(1);
	}
}
// void run_op(char *op, t_stack_node **stack_a, t_stack_node **stack_b)
// {
// 	if (ft_strncmp(op, "sa", 2) == 0)
// 		sa(stack_a);
// 	else if (ft_strncmp(op, "sb", 2) == 0)
// 		sb(stack_b);
// 	else if (ft_strncmp(op, "ss", 2) == 0)
// 		ss(stack_a, stack_b);
// 	else if (ft_strncmp(op, "pa", 2) == 0)
// 		pa(stack_a, stack_b);
// 	else if (ft_strncmp(op, "pb", 2) == 0)
// 		pb(stack_a, stack_b);
// 	else if (ft_strncmp(op, "ra", 2) == 0)
// 		ra(stack_a);
// 	else if (ft_strncmp(op, "rb", 2) == 0)
// 		rb(stack_b);
// 	else if (ft_strncmp(op, "rra", 3) == 0)
// 		rra(stack_a);
// 	else if (ft_strncmp(op, "rrb", 3) == 0)
// 		rrb(stack_b);
// 	else if (ft_strncmp(op, "rrr", 3) == 0)
// 		rrr(stack_a, stack_b);
// 	else if (ft_strncmp(op, "rr", 2) == 0)
// 		rr(stack_a, stack_b);
// 	else
// 	{
// 		if(stack_b)
// 			free_stack(stack_b);
// 		print_error(*stack_a);
// 		exit(1);
// 	}
// }

int main(int argc, char const *argv[])
{
	t_stack_node	*stack_a;
	t_stack_node	*stack_b;
	char *op;
	op = " ";
	if (argc < 2)
		return (1);
	stack_b = NULL;
	stack_a = handle_args(argc, argv);
	while(op)
	{
		op = get_next_line(0);
		if (!op)
		{
			free(op);
			break;
		}
		run_op(op, &stack_a, &stack_b);
		free(op);
	}
	if(stack_sorted(stack_a) && stack_b == NULL)
		ft_printf("OK\n");
	else
	{
		ft_printf("KO\n");
	}
		
	free_stack(&stack_a);
	if(stack_b)
		free_stack(&stack_b);
	return 0;
}

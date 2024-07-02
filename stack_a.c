/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phartman <phartman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 18:08:25 by phartman          #+#    #+#             */
/*   Updated: 2024/07/02 18:34:40 by phartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	process_a(t_stack_node **stack_a, t_stack_node **stack_b)
{
	assign_indexes(*stack_a);
	assign_indexes(*stack_b);
	is_above_median(*stack_a);
	is_above_median(*stack_b);
	assign_target_a(*stack_a, *stack_b);
	find_push_cost_a(*stack_a, *stack_b);
	set_cheapest(*stack_a);
	push_cheapest_a(stack_a, stack_b);
}

void	assign_target_a(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*target;
	t_stack_node	*current_b;
	int				closest;

	while (a)
	{
		closest = INT_MIN;
		current_b = b;
		while (current_b)
		{
			if ((current_b->nbr < a->nbr) && (current_b->nbr > closest))
			{
				closest = current_b->nbr;
				target = current_b;
			}
			current_b = current_b->next;
		}
		if (closest == INT_MIN)
			a->target = stack_max(b);
		else
			a->target = target;
		a = a->next;
	}
}

void	find_push_cost_a(t_stack_node *a, t_stack_node *b)
{
	int	len_a;
	int	len_b;

	len_a = stack_len(a);
	len_b = stack_len(b);
	while (a)
	{
		a->push_cost = a->index;
		if (!(a->above_median))
			a->push_cost = len_a - a->index;
		if (a->target->above_median)
			a->push_cost += a->target->index;
		else
			a->push_cost += len_b - (a->target->index);
		a = a->next;
	}
}

void	rotate_to_top_a(t_stack_node **a, t_stack_node **b,
			t_stack_node *cheapest)
{
	if (cheapest->target->above_median && cheapest->target != *b)
		rb(b);
	else if (!cheapest->target->above_median && cheapest->target != *b)
		rrb(b);
	if (cheapest->above_median && cheapest != *a)
		ra(a);
	else if (!cheapest->above_median && cheapest != *a)
		rra(a);
}

void	push_cheapest_a(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*cheapest;

	cheapest = get_cheapest(*a);
	if (cheapest->above_median && cheapest->target->above_median)
	{
		while (*b != cheapest->target && *a != cheapest)
			rr(a, b);
	}
	else if (!cheapest->above_median && !cheapest->target->above_median)
	{
		while (*b != cheapest->target && *a != cheapest)
			rrr(a, b);
	}
	while (cheapest != *a || cheapest->target != *b)
		rotate_to_top_a(a, b, cheapest);
	if (cheapest == *a && cheapest->target == *b)
	{
		pb(a, b);
		cheapest->cheapest = false;
	}
}

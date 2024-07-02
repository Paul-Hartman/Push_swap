/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phartman <phartman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 18:08:41 by phartman          #+#    #+#             */
/*   Updated: 2024/07/02 18:30:33 by phartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	process_b(t_stack_node **stack_a, t_stack_node **stack_b)
{
	assign_indexes(*stack_a);
	assign_indexes(*stack_b);
	is_above_median(*stack_a);
	is_above_median(*stack_b);
	assign_target_b(*stack_a, *stack_b);
	find_push_cost_b(*stack_a, *stack_b);
	set_cheapest(*stack_b);
	push_cheapest_b(stack_a, stack_b);
}

void	assign_target_b(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*target;
	t_stack_node	*current_a;
	int				closest;

	while (b)
	{
		closest = INT_MAX;
		current_a = a;
		while (current_a)
		{
			if ((current_a->nbr > b->nbr) && (current_a->nbr < closest))
			{
				closest = current_a->nbr;
				target = current_a;
			}
			current_a = current_a->next;
		}
		if (closest == INT_MAX)
			b->target = stack_min(a);
		else
			b->target = target;
		b = b->next;
	}
}

void	find_push_cost_b(t_stack_node *a, t_stack_node *b)
{
	int	len_a;
	int	len_b;

	len_a = stack_len(a);
	len_b = stack_len(b);
	while (b)
	{
		b->push_cost = b->index;
		if (!(b->above_median))
			b->push_cost = len_b - b->index;
		if (b->target->above_median)
			b->push_cost += b->target->index;
		else
			b->push_cost += len_a - (b->target->index);
		b = b->next;
	}
}

void	rotate_to_top_b(t_stack_node **a, t_stack_node **b,
			t_stack_node *cheapest)
{
	if (cheapest->target->above_median && cheapest->target != *a)
		ra(a);
	else if (!cheapest->target->above_median && cheapest->target != *a)
		rra(a);
	if (cheapest->above_median && cheapest != *b)
		rb(b);
	else if (!cheapest->above_median && cheapest != *b)
		rrb(b);
}

void	push_cheapest_b(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*cheapest;

	cheapest = get_cheapest(*b);
	if (cheapest->above_median && cheapest->target->above_median)
	{
		while (*a != cheapest->target && *b != cheapest)
			rr(a, b);
	}
	else if (!cheapest->above_median && !cheapest->target->above_median)
	{
		while (*a != cheapest->target && *b != cheapest)
			rrr(a, b);
	}
	while (cheapest != *b || cheapest->target != *a)
		rotate_to_top_b(a, b, cheapest);
	if (cheapest == *b && cheapest->target == *a)
	{
		pa(a, b);
		cheapest->cheapest = false;
	}
}

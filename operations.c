/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phartman <phartman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 19:02:51 by phartman          #+#    #+#             */
/*   Updated: 2024/06/20 19:27:24 by phartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_a(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*tmp;

	if (*b == NULL)
		return (0);
	tmp = *b;
	*b = (*b)->next;
	if (*b)
		(*b)->prev = NULL;
	tmp->next = *a;
	if (*a)
		(*a)->prev = tmp;
	*a = tmp;
	return (1);
}

int	push_b(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*tmp;

	if (*a == NULL)
		return (0);
	tmp = *a;
	*a = (*a)->next;
	if (*a)
		(*a)->prev = NULL;
	tmp->next = *b;
	if (*b)
		(*b)->prev = tmp;
	*b = tmp;
	return (1);
}

int	rotate(t_stack_node **stack, bool reverse)
{
	t_stack_node	*tmp;
	t_stack_node	*last;

	if (!stack)
		return (0);
	last = stack_last(*stack);
	tmp = *stack;
	if (!reverse)
	{
		*stack = (*stack)->next;
		last->next = tmp;
		tmp->prev = last;
		tmp->next = NULL;
	}
	else
	{
		last->prev->next = NULL;
		*stack = last;
		(*stack)->next = tmp;
		tmp->prev = *stack;
	}
	(*stack)->prev = NULL;
	return (1);
}

int	swap(t_stack_node **stack)
{
	t_stack_node	*tmp;

	if (!stack || !*stack || !(*stack)->next)
		return (0);
	tmp = *stack;
	*stack = (*stack)->next;
	tmp->next = (*stack)->next;
	(*stack)->next = tmp;
	tmp->prev = (*stack);
	(*stack)->prev = NULL;
	stack_last(*stack)->prev = (*stack)->next;
	return (1);
}

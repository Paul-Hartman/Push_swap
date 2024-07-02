/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phartman <phartman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 17:20:27 by phartman          #+#    #+#             */
/*   Updated: 2024/07/02 17:30:39 by phartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack_node **stack, bool reverse)
{
	t_stack_node	*tmp;
	t_stack_node	*last;

	if (!stack)
		return ;
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
	return ;
}

void	ra(t_stack_node **a)
{
	rotate(a, false);
	ft_printf("ra\n");
}

void	rb(t_stack_node **b)
{
	rotate(b, false);
	ft_printf("rb\n");
}

void	rr(t_stack_node **a, t_stack_node **b)
{
	rotate(a, false);
	rotate(b, false);
	ft_printf("rr\n");
}

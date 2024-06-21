/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_wrappers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phartman <phartman@strudent.42berlin.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 17:57:16 by phartman          #+#    #+#             */
/*   Updated: 2024/06/21 17:57:16 by phartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int	swap_both(t_stack_node **a, t_stack_node **b)
{
	int a_valid;
	int b_valid;

	a_valid = swap(a);
	b_valid = swap(b);
	ft_printf("ss\n");
	return (a_valid && b_valid);
}

int	rotate_both(t_stack_node **a, t_stack_node **b, int reverse)
{
	int a_valid;
	int b_valid;

	a_valid = rotate(a, reverse);
	b_valid = rotate(b, reverse);
	if (reverse)
		ft_printf("rrr\n");
	else
		ft_printf("rr\n");
	return (a_valid && b_valid);
}

int	sa(t_stack_node **a)
{
	int a_valid;

	a_valid = swap(a);
	ft_printf("sa\n");
	return (a_valid);
}

int	sb(t_stack_node **b)
{
	int b_valid;

	b_valid = swap(b);
	ft_printf("sb\n");
	return (b_valid);
}

int ra(t_stack_node **a)
{
	int a_valid;

	a_valid = rotate(a, false);
	ft_printf("ra\n");
	return (a_valid);
}

int rb(t_stack_node **b)
{
	int b_valid;

	b_valid = rotate(b, false);
	ft_printf("rb\n");
	return (b_valid);
}

int rra(t_stack_node **a)
{
	int a_valid;

	a_valid = rotate(a, true);
	ft_printf("rra\n");
	return (a_valid);
}


int rrb(t_stack_node **b)
{
	int b_valid;

	b_valid = rotate(b, true);
	ft_printf("rrb\n");
	return (b_valid);
}

int pa(t_stack_node **a, t_stack_node **b)
{
	int a_valid;

	a_valid = push_a(a, b);
	ft_printf("pa\n");
	return (a_valid);
}

int pb(t_stack_node **a, t_stack_node **b)
{
	int b_valid;

	b_valid = push_b(a, b);
	ft_printf("pb\n");
	return (b_valid);
}
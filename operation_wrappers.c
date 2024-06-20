/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_wrappers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phartman <phartman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 19:23:42 by phartman          #+#    #+#             */
/*   Updated: 2024/06/20 19:27:05 by phartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap_both(t_stack_node **a, t_stack_node **b)
{
	int	a_valid;
	int	b_valid;

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
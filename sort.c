/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phartman <phartman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 17:57:07 by phartman          #+#    #+#             */
/*   Updated: 2024/07/02 18:49:44 by phartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack_node **a)
{
	t_stack_node	*max;

	max = stack_max(*a);
	if (*a == max)
		ra(a);
	else if ((*a)->next == max)
		rra(a);
	if ((*a)->nbr > (*a)->next->nbr)
		sa(a);
}

void	sort_two(t_stack_node **a, int len)
{
	if (len == 2)
	{
		if ((*a)->nbr > (*a)->next->nbr)
			sa(a);
	}
}

void	first_push(t_stack_node **a, t_stack_node **b, int len)
{
	if (len == 4)
		pb(a, b);
	else if (len > 4)
	{
		pb(a, b);
		pb(a, b);
	}
	return ;
}

void	min_to_top(t_stack_node **a)
{
	while ((*a)->nbr != stack_min(*a)->nbr)
	{
		if (stack_min(*a)->above_median)
			ra(a);
		else
			rra(a);
	}
}

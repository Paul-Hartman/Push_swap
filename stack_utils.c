/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phartman <phartman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 16:32:07 by phartman          #+#    #+#             */
/*   Updated: 2024/06/20 18:18:19 by phartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_node	*stack_max(t_stack_node *stk)
{
	t_stack_node	*max_node;
	int				max;

	max = INT_MIN;
	if (!stk)
		return (NULL);
	while (stk)
	{
		if (stk->nbr > max)
		{
			max = stk->nbr;
			max_node = stk;
		}
		stk = stk->next;
	}
	return (max_node);
}

t_stack_node	*stack_min(t_stack_node *stk)
{
	t_stack_node	*min_node;
	int				min;

	min = INT_MAX;
	if (!stk)
		return (NULL);
	while (stk)
	{
		if (stk->nbr < min)
		{
			min = stk->nbr;
			min_node = stk;
		}
		stk = stk->next;
	}
	return (min_node);
}

t_stack_node	*stack_last(t_stack_node *stk)
{
	t_stack_node	*tmp;

	if (!stk)
		return (NULL);
	tmp = stk;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

t_stack_node	*get_cheapest(t_stack_node *a)
{
	t_stack_node	*tmp;

	tmp = a;
	while (tmp)
	{
		if (tmp->cheapest)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

int	stack_len(t_stack_node *stk)
{
	t_stack_node	*tmp;
	int				len;

	len = 0;
	tmp = stk;
	while (tmp)
	{
		len++;
		tmp = tmp->next;
	}
	return (len);
}

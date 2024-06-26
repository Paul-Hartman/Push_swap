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
	t_stack_node	*tmp;
	t_stack_node	*max_node;
	int				max;

	max = INT_MIN;
	if (!stk)
		return (NULL);
	tmp = stk;
	while (tmp->next)
	{
		if (tmp->nbr > max)
		{
			max = tmp->nbr;
			max_node = tmp;
		}
		tmp = tmp->next;
	}
	return (max_node);
}

t_stack_node	*stack_min(t_stack_node *stk)
{
	t_stack_node	*tmp;
	t_stack_node	*min_node;
	int				min;

	min = INT_MAX;
	if (!stk)
		return (NULL);
	tmp = stk;
	while (tmp->next)
	{
		if (tmp->nbr < min)
		{
			min = tmp->nbr;
			min_node = tmp;
		}
		tmp = tmp->next;
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

void	stack_add(t_stack_node **stk, int n)
{
	t_stack_node	*new;
	t_stack_node	*last_node;

	if (!stk)
		return ;
	new = malloc(sizeof(t_stack_node));
	if (!new)
		print_error("malloc failed");
	new->nbr = n;
	new->next = NULL;
	new->prev = NULL;
	if (!*stk)
	{
		new->prev = NULL;
		*stk = new;
	}
	else
	{
		last_node = stack_last(*stk);
		last_node->next = new;
		new->prev = last_node;
	}
}

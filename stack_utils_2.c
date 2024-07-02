/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phartman <phartman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 18:45:59 by phartman          #+#    #+#             */
/*   Updated: 2024/07/02 18:52:15 by phartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	assign_indexes(t_stack_node *stack)
{
	t_stack_node	*tmp;
	int				i;

	i = 0;
	tmp = stack;
	while (tmp)
	{
		tmp->index = i;
		tmp = tmp->next;
		i++;
	}
}

void	is_above_median(t_stack_node *stack)
{
	t_stack_node	*tmp;
	int				median;

	median = stack_len(stack) / 2;
	tmp = stack;
	while (tmp)
	{
		if (tmp->index <= median)
			tmp->above_median = true;
		else
			tmp->above_median = false;
		tmp = tmp->next;
	}
}

void	set_cheapest(t_stack_node *stack)
{
	t_stack_node	*cheapest;
	int				cheapest_value;

	if (!stack)
		return ;
	cheapest_value = INT_MAX;
	while (stack)
	{
		if (stack->push_cost < cheapest_value)
		{
			cheapest = stack;
			cheapest_value = stack->push_cost;
		}
		stack = stack->next;
	}
	cheapest->cheapest = true;
}

void	stack_add(t_stack_node **stk, int n)
{
	t_stack_node	*new;
	t_stack_node	*last_node;

	if (!stk)
		return ;
	new = malloc(sizeof(t_stack_node));
	if (!new)
		print_error(*stk);
	new->nbr = n;
	new->next = NULL;
	new->prev = NULL;
	new->cheapest = false;
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

void	free_stack(t_stack_node **stk)
{
	t_stack_node	*current_node;
	t_stack_node	*next_node;

	current_node = *stk;
	while (current_node != NULL)
	{
		next_node = current_node->next;
		free(current_node);
		current_node = next_node;
	}
	*stk = NULL;
	free(*stk);
}

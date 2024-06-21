/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phartman <phartman@strudent.42berlin.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 17:57:07 by phartman          #+#    #+#             */
/*   Updated: 2024/06/22 01:41:51 by phartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int sort_three(t_stack_node **a)
// {
// 	int first;
// 	int second;
// 	int third;
// 	int a_valid;

// 	first = (*a)->nbr;
// 	second = (*a)->next->nbr;
// 	third = (*a)->next->next->nbr;

// 	if (first > second && second < third && first < third)
// 		a_valid = sa(a);
// 	else if (first > second && second > third && first > third)
// 	{
// 		a_valid = sa(a);
// 		a_valid = rra(a);
// 	}
// 	else if (first > second && second < third && first > third)
// 		a_valid = ra(a);
// 	else if (first < second && second > third && first < third)
// 	{
// 		a_valid = sa(a);
// 		a_valid = ra(a);
// 	}
// 	else if (first < second && second > third && first > third)
// 		a_valid = rra(a);

// 	return (a_valid);
// }

int sort_three(t_stack_node **a)
{
	int first;
	int second;
	int max_value;
	int a_valid;

	max_value = stack_max(*a)->nbr;
	first = (*a)->nbr;
	second = (*a)->next->nbr;
	a_valid = 0;

	if (first == max_value)
	{
		a_valid = ra(a);
		if (first > second)
			a_valid = sa(a);
	}
	else if (second == max_value)
	{
		a_valid = rra(a);
		a_valid = sa(a);
	}
	else if (first > second)
	{
		a_valid = sa(a);
	}
	return (a_valid);
}

int first_push(t_stack_node **a, t_stack_node **b, int len)
{
	int a_valid;
	if(len == 4)
		a_valid = pb(a, b);
	else if (len > 4)
	{
		a_valid = pb(a, b);
		a_valid = pb(a, b);
	}
	return (a_valid);
}



void assign_indexes(t_stack_node *stack)
{
	t_stack_node *tmp;
	int i;

	i = 0;
	tmp = stack;
	while (tmp)
	{
		tmp->index = i;
		tmp = tmp->next;
		i++;
	}
}

void assign_target_b(t_stack_node **a, t_stack_node **b)
{
	t_stack_node *tmp_a;
	t_stack_node *tmp_b;
	t_stack_node *max;
	t_stack_node *min;
	t_stack_node *closest;

	max = stack_max(*b);
	min = stack_min(*b);
	tmp_a = *a;
	closest = max;
	tmp_b = *b;
	while (tmp_a)
	{
		if (tmp_a->nbr < min->nbr)
		{
			tmp_a->target = max;
			tmp_a = tmp_a->next;
			continue ;
		}
		while (tmp_b)
		{
			if ((tmp_b->nbr < tmp_a->nbr) && (tmp_b->nbr > closest->nbr))
				closest = tmp_b;
			tmp_b = tmp_b->next;
		}
		tmp_a->target = closest;
		tmp_a = tmp_a->next;
	}
}

int find_median(t_stack_node *stack)
{
	int median;

	median = stack_len(stack)/2;

	return (median);
}


int find_push_cost(t_stack_node **a, t_stack_node **b)
{
	int cost_a;

	int cost_b;

	t_stack_node *tmp_a;
	if(tmp_a->index < find_median(*a))
		cost_a = tmp_a->index;
	else
		cost_a = stack_len(*a) - tmp_a->index;

	if(tmp_a->target->index < find_median(*b))
		cost_b = tmp_a->target->index;
	else
		cost_b = stack_len(*b) - tmp_a->target->index;

	return (cost_a + cost_b);
}


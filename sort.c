/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phartman <phartman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 17:57:07 by phartman          #+#    #+#             */
/*   Updated: 2024/06/26 17:01:29 by phartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_three(t_stack_node **a)
{
	t_stack_node	*max;
	int				a_valid;

	max = stack_max(*a);
	a_valid = 0;
	if (*a == max)
		a_valid = ra(a);
	else if ((*a)->next == max)
		a_valid = rra(a);
	if ((*a)->nbr > (*a)->next->nbr)
		a_valid = sa(a);
	return (a_valid);
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

void	assign_target_b(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*tmp_a;
	t_stack_node	*tmp_b;
	t_stack_node	*max;
	t_stack_node	*min;
	t_stack_node	*closest;

	max = stack_max(*b);
	min = stack_min(*b);
	tmp_a = *a;
	closest = max;
	tmp_b = *b;
	while (tmp_a)
	{
		tmp_b = *b;
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

void	assign_target_a(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*tmp_a;
	t_stack_node	*tmp_b;
	t_stack_node	*max;
	t_stack_node	*min;
	t_stack_node	*closest;

	max = stack_max(*a);
	min = stack_min(*a);
	tmp_a = *a;
	closest = max;
	tmp_b = *b;
	while (tmp_b)
	{
		tmp_a = *a;
		if (tmp_b->nbr > max->nbr)
		{
			tmp_b->target = min;
			tmp_b = tmp_b->next;
			continue ;
		}
		while (tmp_a)
		{
			if ((tmp_a->nbr > tmp_b->nbr) && (tmp_a->nbr < closest->nbr))
				closest = tmp_a;
			tmp_a = tmp_a->next;
		}
		tmp_b->target = closest;
		tmp_b = tmp_b->next;
	}
}

void	is_above_median(t_stack_node **stack)
{
	t_stack_node	*tmp;
	int				median;

	median = stack_len(*stack) / 2;
	tmp = *stack;
	while (tmp)
	{
		if (tmp->index <= median)
			tmp->above_median = true;
		else
			tmp->above_median = false;
		tmp = tmp->next;
	}
}

int	find_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int	find_push_cost(t_stack_node **a, t_stack_node **b)
{
	int				cost_a;
	int				cost_b;
	t_stack_node	*tmp_a;

	tmp_a = *a;
	while (tmp_a)
	{
		if(stack_len(*b) == 2 && tmp_a->index == 1 && tmp_a->target->index == 1)
		{
			tmp_a->push_cost = 1;
			tmp_a = tmp_a->next;
			continue ;
		}
		if (tmp_a->above_median)
			cost_a = tmp_a->index;
		else
			cost_a = stack_len(*a) - tmp_a->index;
		if (tmp_a->target->above_median)
			cost_b = tmp_a->target->index;
		else
			cost_b = stack_len(*b) - tmp_a->target->index;
		tmp_a->push_cost = cost_a + cost_b;
		if (tmp_a->above_median && tmp_a->target->above_median)
			tmp_a->push_cost -= find_min(tmp_a->index, tmp_a->target->index);
		else if (!tmp_a->above_median && !tmp_a->target->above_median)
			tmp_a->push_cost -= find_min(stack_len(*a) - tmp_a->index,
					stack_len(*b) - tmp_a->target->index);
		tmp_a = tmp_a->next;
	}
	return (1);
}

t_stack_node *find_cheapest(t_stack_node **stack)
{
	t_stack_node	*tmp;
	t_stack_node	*cheapest;

	tmp = *stack;
	cheapest = tmp;
	while (tmp)
	{
		if (tmp->push_cost < cheapest->push_cost)
			cheapest = tmp;
		tmp = tmp->next;
	}
	return (cheapest);
}

void	push_cheapest(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*cheapest;
	int i;
	
	i = 0;

	cheapest = find_cheapest(a);
	if(cheapest->above_median && cheapest->target->above_median)
	{
		while(i++ < find_min(cheapest->index, cheapest->target->index))
			rr(a, b);
	}
	else if (!cheapest->above_median && !cheapest->target->above_median)
	{
		while(i++ < find_min(cheapest->index, cheapest->target->index))
			rrr(a, b);
	}
	while(cheapest != *a || cheapest->target != *b)
	{
		if(cheapest->target->above_median && cheapest->target != *b)
			rb(b);
		else if(!cheapest->target->above_median && cheapest->target != *b)
			rrb(b);
		if(cheapest->above_median && cheapest != *a)
			ra(a);
		else if(!cheapest->above_median && cheapest != *a)
			rra(a);
		i++;
	}
	if(cheapest == *a && cheapest->target == *b)
		pb(a, b);
}

void min_to_top(t_stack_node **a)
{
	t_stack_node *min;

	min = stack_min(*a);
	assign_indexes(*a);
	is_above_median(a);
	if(min->above_median)
	{
		while(min != *a)
		{
			ra(a);
		}
	}
	else
	{
		while(min != *a)
		{
			rra(a);
		}
	}
}

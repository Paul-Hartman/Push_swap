/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phartman <phartman@strudent.42berlin.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 17:57:07 by phartman          #+#    #+#             */
/*   Updated: 2024/06/25 19:12:30 by phartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int sort_three(t_stack_node **a)
{
	t_stack_node *max;
	int a_valid;

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


// int find_push_cost(t_stack_node **a, t_stack_node **b)
// {
// 	int cost_a;

// 	int cost_b;

// 	t_stack_node *tmp_a;

// 	tmp_a = *a;
// 	while(tmp_a)
// 	{
// 		if(tmp_a->index < find_median(*a))
// 			cost_a = tmp_a->index;
// 			tmp_a->above_median = true;
// 		else
// 			cost_a = stack_len(*a) - tmp_a->index;

// 		if(tmp_a->target->index < find_median(*b))
// 			cost_b = tmp_a->target->index;
			
// 		else
// 			cost_b = stack_len(*b) - tmp_a->target->index;

// 		tmp_a->push_cost = cost_a + cost_b;
// 		tmp_a = tmp_a->next;
// 	}
// 	return (1);
// }

// int push_cheapest()


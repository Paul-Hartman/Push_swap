/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phartman <phartman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 17:57:07 by phartman          #+#    #+#             */
/*   Updated: 2024/07/02 16:30:35 by phartman         ###   ########.fr       */
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

	if (len == 2)
	{
		if((*a)->nbr > (*a)->next->nbr)
			sa(a);
		else
			return ;
	}
	
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

void	assign_target_a(t_stack_node *a, t_stack_node *b)
{

	t_stack_node	*target;
	t_stack_node	*current_b;

	int	closest;


	while (a)
	{
		closest = INT_MIN;
		current_b = b;
		while (current_b)
		{
			if ((current_b->nbr < a->nbr) && (current_b->nbr > closest))
			{
				closest = current_b->nbr;
				target = current_b;
			}
				
			current_b = current_b->next;
		}
		if (closest == INT_MIN)
			a->target = stack_max(b);
		else
			a->target = target;
		a = a->next;
	}
}

void	assign_target_b(t_stack_node *a, t_stack_node *b)
{

	t_stack_node	*target;
	t_stack_node	*current_a;

	int	closest;


	while (b)
	{
		closest = INT_MAX;
		current_a = a;
		while (current_a)
		{
			if ((current_a->nbr > b->nbr) && (current_a->nbr < closest))
			{
				closest = current_a->nbr;
				target = current_a;
			}
				
			current_a = current_a->next;
		}
		if (closest == INT_MAX)
			b->target = stack_min(a);
		else
			b->target = target;
		b = b->next;
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

void find_push_cost_a(t_stack_node *a, t_stack_node *b)
{
	int len_a;
	int len_b;

	len_a = stack_len(a);
	len_b = stack_len(b);
	while(a)
	{
		a->push_cost = a->index;
		if(!(a->above_median))
			a->push_cost = len_a - a->index;
		if(a->target->above_median)
			a->push_cost += a->target->index;
		else
			a->push_cost += len_b - (a->target->index);
		a = a->next;
	}
}



int find_min(int a , int b)
{
	if(a < b)
		return a;
	return b;
}


void find_push_cost_b(t_stack_node *a, t_stack_node *b)
{
	int len_a;
	int len_b;

	len_a = stack_len(a);
	len_b = stack_len(b);
	while(b)
	{
		b->push_cost = b->index;
		if(!(b->above_median))
			b->push_cost = len_b - b->index;
		if(b->target->above_median)
			b->push_cost += b->target->index;
		else
			b->push_cost += len_a - (b->target->index);
		b = b->next;

	}
}

// int	find_push_cost(t_stack_node **a, t_stack_node **b)
// {
// 	int				cost_a;
// 	int				cost_b;
// 	t_stack_node	*tmp_a;

// 	tmp_a = *a;
// 	while (tmp_a)
// 	{
// 		if(stack_len(*b) == 2 && tmp_a->index == 1 && tmp_a->target->index == 1)
// 		{
// 			tmp_a->push_cost = 1;
// 			tmp_a = tmp_a->next;
// 			continue ;
// 		}
// 		if (tmp_a->above_median)
// 			cost_a = tmp_a->index;
// 		else
// 			cost_a = stack_len(*a) - tmp_a->index;
// 		if (tmp_a->target->above_median)
// 			cost_b = tmp_a->target->index;
// 		else
// 			cost_b = stack_len(*b) - tmp_a->target->index;
// 		tmp_a->push_cost = cost_a + cost_b;
// 		if (tmp_a->above_median && tmp_a->target->above_median)
// 			tmp_a->push_cost -= find_min(tmp_a->index, tmp_a->target->index);
// 		else if (!tmp_a->above_median && !tmp_a->target->above_median)
// 			tmp_a->push_cost -= find_min(stack_len(*a) - tmp_a->index,
// 					stack_len(*b) - tmp_a->target->index);
// 		tmp_a = tmp_a->next;
// 	}
// 	return (1);
// }

void set_cheapest(t_stack_node *stack)
{
	t_stack_node	*cheapest;
	int cheapest_value;

	if(!stack)
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

// void	push_cheapest_b(t_stack_node **a, t_stack_node **b)
// {
// 	t_stack_node	*cheapest;
// 	int i;
	
// 	i = 0;

	
// 	cheapest = get_cheapest(*b);
// 	if(cheapest->above_median && cheapest->target->above_median)
// 	{
// 		while(*a != cheapest->target
// 		&& *b != cheapest)
// 			rr(a, b);
// 	}
// 	else if (!cheapest->above_median && !cheapest->target->above_median)
// 	{
// 		while(*a != cheapest->target
// 		&& *b != cheapest)
// 			rrr(a, b);
// 	}
// 	while(cheapest != *b || cheapest->target != *a)
// 	{
// 		if(cheapest->target->above_median && cheapest->target != *a)
// 			rb(b);
// 		else if(!cheapest->target->above_median && cheapest->target != *a)
// 			rrb(b);
// 		if(cheapest->above_median && cheapest != *b)
// 			ra(a);
// 		else if(!cheapest->above_median && cheapest != *b)
// 			rra(a);
// 		i++;
// 	}
// 	if(cheapest == *b && cheapest->target == *a)
// 		pa(a, b);
// }


// void	push_cheapest_a(t_stack_node **a, t_stack_node **b)
// {
// 	t_stack_node	*cheapest;
// 	int i;
	
// 	i = 0;

// 	cheapest = get_cheapest(*a);
// 	if(cheapest->above_median && cheapest->target->above_median)
// 	{
// 		while(*b != cheapest->target
// 		&& *a != cheapest)
// 			rr(a, b);
// 	}
// 	else if (!cheapest->above_median && !cheapest->target->above_median)
// 	{
		// while(*b != cheapest->target
		// && *a != cheapest)
// 			rrr(a, b);
// 	}
// 	while(cheapest != *a || cheapest->target != *b)
// 	{
// 		if(cheapest->above_median && cheapest != *a)
// 			ra(a);
// 		else if(!cheapest->above_median && cheapest != *a)
// 			rra(a);
// 		if(cheapest->target->above_median && cheapest->target != *b)
// 			rb(b);
// 		else if(!cheapest->target->above_median && cheapest->target != *b)
// 			rrb(b);
// 		i++;
// 	}
// 	if(cheapest == *a && cheapest->target == *b)
// 		pb(a, b);

// }


void push_cheapest_a(t_stack_node **a, t_stack_node **b) {
    t_stack_node *cheapest;
    int i = 0;

    cheapest = get_cheapest(*a);
    if (cheapest->above_median && cheapest->target->above_median) {
        		while(*b != cheapest->target && *a != cheapest)
            		rr(a, b);
    } else if (!cheapest->above_median && !cheapest->target->above_median) {
        		while(*b != cheapest->target && *a != cheapest)
            		rrr(a, b);
    }
    while (cheapest != *a || cheapest->target != *b) {
        if (cheapest->target->above_median && cheapest->target != *b)
            rb(b);
        else if (!cheapest->target->above_median && cheapest->target != *b)
            rrb(b);
        if (cheapest->above_median && cheapest != *a)
            ra(a);
        else if (!cheapest->above_median && cheapest != *a)
            rra(a);
        i++;
    }
    if (cheapest == *a && cheapest->target == *b)
	{
        pb(a, b);
		cheapest->cheapest = false;
	}

	
}


void push_cheapest_b(t_stack_node **a, t_stack_node **b) {
    t_stack_node *cheapest;
    int i = 0;

    cheapest = get_cheapest(*b); // Notice we get the cheapest from *b now
    if (cheapest->above_median && cheapest->target->above_median) {
        		while(*a != cheapest->target && *b != cheapest)
            		rr(a, b);
    } else if (!cheapest->above_median && !cheapest->target->above_median) {
        		while(*a != cheapest->target && *b != cheapest)
            		rrr(a, b);
	}
    while (cheapest != *b || cheapest->target != *a) { // Adjusted for *b and *a
        if (cheapest->target->above_median && cheapest->target != *a)
            ra(a); // Adjusted for *a
        else if (!cheapest->target->above_median && cheapest->target != *a)
            rra(a); // Adjusted for *a
        if (cheapest->above_median && cheapest != *b)
            rb(b); // Adjusted for *b
        else if (!cheapest->above_median && cheapest != *b)
            rrb(b); // Adjusted for *b
        i++;
    }
    if (cheapest == *b && cheapest->target == *a)
	{
        pa(a, b); // Adjusted for pushing to *a
		cheapest->cheapest = false;
	}
}


void	push_cheapest(t_stack_node **a, t_stack_node **b, char stack)
{
	t_stack_node	*cheapest;
	int i;
	
	i = 0;

	cheapest = get_cheapest(*a);
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
	if(cheapest == *a && cheapest->target == *b && stack == 'a')
		pb(a, b);
	else if(cheapest == *a && cheapest->target == *b && stack == 'b')
		pa(b, a);
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

// void min_to_top(t_stack_node **a)
// {
// 	t_stack_node *min;

// 	min = stack_min(*a);
// 	assign_indexes(*a);
// 	is_above_median(a);
// 	if(min->above_median)
// 	{
// 		while(min != *a)
// 		{
// 			ra(a);
// 		}
// 	}
// 	else
// 	{
// 		while(min != *a)
// 		{
// 			rra(a);
// 		}
// 	}
// }

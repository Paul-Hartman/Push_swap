/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phartman <phartman@strudent.42berlin.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 17:57:07 by phartman          #+#    #+#             */
/*   Updated: 2024/06/21 19:17:48 by phartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int sort_three(t_stack_node **a)
{
	int first;
	int second;
	int third;
	int a_valid;

	first = (*a)->nbr;
	second = (*a)->next->nbr;
	third = (*a)->next->next->nbr;

	if (first > second && second < third && first < third)
		a_valid = sa(a);
	else if (first > second && second > third && first > third)
	{
		a_valid = sa(a);
		a_valid = rra(a);
	}
	else if (first > second && second < third && first > third)
		a_valid = ra(a);
	else if (first < second && second > third && first < third)
	{
		a_valid = sa(a);
		a_valid = ra(a);
	}
	else if (first < second && second > third && first > third)
		a_valid = rra(a);

	return (a_valid);
}
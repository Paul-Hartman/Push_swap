/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phartman <phartman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 17:25:51 by phartman          #+#    #+#             */
/*   Updated: 2024/07/02 17:26:29 by phartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrr(t_stack_node **a, t_stack_node **b)
{
	rotate(a, true);
	rotate(b, true);
	ft_printf("rrr\n");
}

void	rra(t_stack_node **a)
{
	rotate(a, true);
	ft_printf("rra\n");
}

void	rrb(t_stack_node **b)
{
	rotate(b, true);
	ft_printf("rrb\n");
}

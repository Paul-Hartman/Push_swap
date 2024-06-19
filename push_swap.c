/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phartman <phartman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 14:18:44 by phartman          #+#    #+#             */
/*   Updated: 2024/06/19 18:06:05 by phartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int swap(t_stack *stack)
{
	t_list *tmp;

	if (!stack || !stack->top || !stack->top->next)
		return (0);
	tmp = stack->top;
	stack->top = stack->top->next;
	tmp->next = stack->top->next;
	stack->top->next = tmp;
	return (1);
}

int swap_both(t_stack *a, t_stack *b)
{
	return (swap(a) && swap(b));
}

int push_a(t_stack *a, t_stack *b)
{
	t_list *tmp;
	if(a->top == NULL)
		return (0);
	ft_lstadd_front(b->top, a->top);
	a->top = a->top->next;
	return (0);
}

int push_b(t_stack *a, t_stack *b)
{
	if(b->top == NULL)
		return (0);
	ft_lstadd_front(a->top, b->top);
	b->top = b->top->next;
	return (0);
}

int rotate(t_stack *stack, int reverse)
{
	t_list *tmp;
	if(!stack)
		return (0);
	if(!reverse)
	{
		tmp = stack->top;
		stack->top = stack->top->next;
		stack->bottom->next = tmp;
		stack->bottom = tmp;
	}
	else
	{
		tmp = stack->bottom;
		stack->bottom = stack->bottom->prev;
		tmp->next = stack->top;
		stack->top = tmp;
	}
}

int rotate_both(t_stack *a, t_stack *b, int reverse)
{
	return (rotate(a, reverse) && rotate(b, reverse));
}



t_stack init_stack(char **argv)
{
	t_stack stack;
	t_list *new;
	int i;

	stack.top = NULL;
	stack.bottom = NULL;
	i = 0;
	while (argv[i])
	{
		new = ft_lstnew(ft_atoi(argv[i]));
		if (!new)
			return (stack);
		ft_lstadd_back(&stack.top, new);
		if (!stack.bottom)
			stack.bottom = stack.top;
		i++;
	}
	return (stack);
}

int print_error(void)
{
	ft_putstr_fd("Error\n", 2);
	return (0);
}

int main(int argc, char const *argv[])
{
	if(argc < 2)
		print_error();
	else
	{
		t_stack a;
		t_stack b;
		a = init_stack(argv);
		b.top = NULL;
		b.bottom = NULL;
		if a.top > a.top.next;
		swap(a);
	if a.top > a.bottom;
		rotate(a, 1);
	}
	return 0;
}

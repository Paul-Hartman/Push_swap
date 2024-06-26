/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phartman <phartman@strudent.42berlin.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 17:57:25 by phartman          #+#    #+#             */
/*   Updated: 2024/06/21 17:57:25 by phartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int	print_error(char *msg)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(msg, 2);
	exit(1);
	return (0);
}

t_stack_node	*handle_args(int argc, char const *argv[])
{
	int i;
	int j;
	t_stack_node *stack;
	char **args;
	long int num;

	stack = NULL;
	i = 1;
	while (i < argc)
	{
		j = 0;
		args = ft_split(argv[i], ' ');
		while (args[j])
		{
			num = ft_atol(args[j]);
			if (num == 0 && args[j][0] != '0')
				print_error("invalid argument");
			if (num > INT_MAX || num < INT_MIN)
				print_error("argument to large or too small");
			if (check_stack(stack, num))
				print_error("duplicate argument");
			stack_add(&stack, num);
			j++;
		}
		i++;
	}
	return (stack);
}

int	check_stack(t_stack_node *stack, int num)
{
	t_stack_node *tmp;

	tmp = stack;
	while (tmp)
	{
		if (tmp->nbr == num)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

bool	stack_sorted(t_stack_node *stack)
{
	t_stack_node *tmp;

	tmp = stack;
	while (tmp->next)
	{
		if (tmp->nbr > tmp->next->nbr)
			return (false);
		tmp = tmp->next;
	}
	return (true);
}

void	print_stack(t_stack_node *stack)
{
	t_stack_node *tmp;

	tmp = stack;
	while (tmp)
	{
		ft_printf("%d\n", tmp->nbr);
		tmp = tmp->next;
	}
}

int	main(int argc, const char *argv[])
{
	t_stack_node *stack_a;
	//t_stack_node *stack_b;

	//stack_b = NULL;
	if (argc < 2)
		return (print_error("no arguments provided"));
	else if (strlen(argv[1]) == 0)
		return (print_error("empty argument provided"));
	else
		stack_a = handle_args(argc, argv);
	printf("stack A:\n");
	print_stack(stack_a);
	sa(&stack_a);
	rra(&stack_a);
	// if(!stack_sorted(stack_a))
	// {
	// 	sort_three(&stack_a);
	// }
	printf("swapped A\n");
	printf("stack A:\n");
	print_stack(stack_a);
	return (0);
}

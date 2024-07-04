/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_checks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phartman <phartman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 14:45:50 by phartman          #+#    #+#             */
/*   Updated: 2024/07/04 18:27:54 by phartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	print_error(t_stack_node *stack)
{
	ft_putstr_fd("Error\n", 2);
	if (stack)
		free_stack(&stack);
	exit (1);
	return (0);
}

bool	all_digits(char *str)
{
	if (*str == '-')
		str++;
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (false);
		str++;
	}
	return (true);
}

t_stack_node	*handle_args(int argc, char const *argv[])
{
	int				i;
	int				j;
	t_stack_node	*stack;
	char			**args;
	long int		num;

	stack = NULL;
	i = 1;
	while (i < argc)
	{
		j = 0;
		args = ft_split(argv[i++], ' ');
		if (!args || !args[0])
			print_error(NULL);
		while (args[j])
		{
			num = ft_atol(args[j]);
			is_valid(num, args, j, stack);
			stack_add(&stack, num);
			free(args[j++]);
		}
		free(args);
	}
	return (stack);
}

int	check_dups(t_stack_node *stack, int num)
{
	t_stack_node	*tmp;

	tmp = stack;
	while (tmp)
	{
		if (tmp->nbr == num)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	is_valid(long int num, char **args, int j, t_stack_node *stack)
{
	if ((num == 0 && args[j][0] != '0') || !check_dups(stack, num)
					|| num > INT_MAX || num < INT_MIN || !all_digits(args[j])
					|| ft_strlen(args[j]) > 11 || !args)
		print_error(stack);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrooks- <cbrooks-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 16:11:06 by cbrooks-          #+#    #+#             */
/*   Updated: 2026/01/29 14:26:51 by cbrooks-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*error_msg(char **stack, int argc)
{
	if (argc == 2)
		free_chr(stack);
	write(2, "Error\n", 6);
	return ((int *)0);
}

int	find_max(int *stack, int length)
{
	int	max;
	int	i;

	max = INT_MIN;
	i = 0;
	while (i < length)
	{
		if (stack[i] > max)
			max = stack[i];
		i++;
	}
	return (max);
}

int	check_doubles(int *stack, int length)
{
	int	i;
	int	j;

	i = 0;
	while (i < length)
	{
		j = i + 1;
		while (j < length)
		{
			if (stack[i] == stack[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_nbr(char *argv)
{
	int	i;

	i = 0;
	if (argv[i] == '-' || argv[i] == '+')
		i++;
	while (argv[i])
	{
		if (!ft_isdigit(argv[i]))
			return (0);
		i++;
	}
	return (1);
}

int	*validate_input(int argc, char **argv, int *stack_a, int *length)
{
	int		i;
	long	tmp_argv;
	char	**tmp_stack;

	i = 0;
	if (argc == 2)
		tmp_stack = ft_split(argv[1], ' ');
	else
		tmp_stack = argv + 1;
	while (tmp_stack[i])
	{
		if (!check_nbr(tmp_stack[i]))
			return (error_msg(tmp_stack, argc));
		tmp_argv = ft_atoi(tmp_stack[i]);
		if (tmp_argv < INT_MIN || tmp_argv > INT_MAX)
			return (error_msg(tmp_stack, argc));
		stack_a[i] = ft_atoi(tmp_stack[i]);
		i++;
	}
	*length = i;
	if (check_doubles(stack_a, *length))
		return (error_msg(tmp_stack, argc));
	if (argc == 2)
		free_chr(tmp_stack);
	return (stack_a);
}

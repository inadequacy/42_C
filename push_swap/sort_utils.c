/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrooks- <	cbrooks-@student.42berlin.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 16:14:55 by cbrooks-          #+#    #+#             */
/*   Updated: 2026/01/28 11:53:54 by cbrooks-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(int *stack)
{
	int	placeholder;

	placeholder = stack[0];
	stack[0] = stack[1];
	stack[1] = placeholder;
	write(1, "sa\n", 3);
}

void	rotate_a(int *stack, int length)
{
	int	placeholder;
	int	i;

	placeholder = stack[0];
	i = 0;
	while (i < length - 1)
	{
		stack[i] = stack[i + 1];
		i++;
	}
	stack[length - 1] = placeholder;
	write(1, "ra\n", 3);
}

void	r_rotate_a(int *stack, int length)
{
	int	placeholder;
	int	i;

	placeholder = stack[length - 1];
	i = length - 1;
	while (i > 0)
	{
		stack[i] = stack[i - 1];
		i--;
	}
	stack[0] = placeholder;
	write(1, "rra\n", 4);
}

void	push_b(int *stack_a, int *stack_b, int *lengths)
{
	int	i;

	i = lengths[1];
	while (i > 0)
	{
		stack_b[i] = stack_b[i - 1];
		i--;
	}
	stack_b[0] = stack_a[0];
	(lengths[1])++;
	i = 0;
	while (i < lengths[0] - 1)
	{
		stack_a[i] = stack_a[i + 1];
		i++;
	}
	(lengths[0])--;
	write(1, "pb\n", 3);
}

void	push_a(int *stack_a, int *stack_b, int *lengths)
{
	int	i;

	i = lengths[0];
	while (i > 0)
	{
		stack_a[i] = stack_a[i - 1];
		i--;
	}
	stack_a[0] = stack_b[0];
	(lengths[0])++;
	i = 0;
	while (i < lengths[1] - 1)
	{
		stack_b[i] = stack_b[i + 1];
		i++;
	}
	(lengths[1])--;
	write(1, "pa\n", 3);
}

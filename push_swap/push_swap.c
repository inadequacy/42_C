/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrooks- <cbrooks-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 11:09:01 by cbrooks-          #+#    #+#             */
/*   Updated: 2026/01/29 14:45:10 by cbrooks-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(int *stack, int length)
{
	int	max;

	max = find_max(stack, length);
	if (stack[0] == max)
		rotate_a(stack, length);
	else if (stack[1] == max)
		r_rotate_a(stack, length);
	if (stack[0] > stack[1])
		swap_a(stack);
}

void	sort_five(int *stack_a, int length)
{
	int	*stack_b;
	int	*lengths;

	stack_b = malloc(sizeof(int) * length);
	lengths = malloc(sizeof(int) * 2);
	lengths[0] = length;
	lengths[1] = 0;
	if (!stack_b || !lengths)
		return ;
	normalize(stack_a, length);
	while (length--)
	{
		if (stack_a[0] == 0 || stack_a[0] == 1)
			push_b(stack_a, stack_b, lengths);
		else
			rotate_a(stack_a, lengths[0]);
	}
	sort_three(stack_a, lengths[0]);
	push_a(stack_a, stack_b, lengths);
	push_a(stack_a, stack_b, lengths);
	if (stack_a[0] > stack_a[1])
		swap_a(stack_a);
	free(stack_b);
	free(lengths);
}

void	radix_function(int *stack_a, int *stack_b, int *lengths, int bit)
{
	int	i;
	int	current_length;

	i = 0;
	current_length = lengths[0];
	while (i < current_length)
	{
		if (((stack_a[0] >> bit) & 1) == 0)
			push_b(stack_a, stack_b, lengths);
		else
			rotate_a(stack_a, lengths[0]);
		i++;
	}
	while (lengths[1] > 0)
		push_a(stack_a, stack_b, lengths);
}

void	push_swap(int *stack_a, int length)
{
	int	*stack_b;
	int	*lengths;
	int	max_bits;
	int	bit;

	stack_b = malloc(sizeof(int) * length);
	lengths = malloc(sizeof(int) * 2);
	if (!stack_b || !lengths)
		return ;
	lengths[0] = length;
	lengths[1] = 0;
	max_bits = 0;
	normalize(stack_a, length);
	while ((length - 1) >> max_bits)
		max_bits++;
	bit = 0;
	while (bit < max_bits)
	{
		radix_function(stack_a, stack_b, lengths, bit);
		bit++;
	}
	free(stack_b);
	free(lengths);
}

int	main(int argc, char **argv)
{
	int	*stack_a;
	int	*tmp;
	int	length;

	if (argc < 2)
		return (0);
	if (argc != 2)
		stack_a = malloc((argc - 1) * sizeof(int));
	else
		stack_a = malloc(det_length(argv[1]) * sizeof(int));
	length = 0;
	tmp = stack_a;
	stack_a = validate_input(argc, argv, stack_a, &length);
	if (!stack_a)
		free(tmp);
	if (!stack_a)
		return (1);
	if (length <= 3 && length != 0 && !check_order(stack_a, length))
		sort_three(stack_a, length);
	if (length <= 5 && length > 3 && !check_order(stack_a, length))
		sort_five(stack_a, length);
	if (length > 5 && !check_order(stack_a, length))
		push_swap(stack_a, length);
	free(stack_a);
	return (0);
}

/*
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int	check_order(int *stack, int total_len, int current_len)
{
	int	i;

	if (total_len != current_len)
		return (0);
	i = 0;
	while (i < total_len)
	{
		if (stack[i] < stack[i + 1])
			i++;
		if (i == total_len)
			return (1);
		if (stack[i] > stack[i + 1])
			return (0);
	}
	return (0);
}

int	det_order(int *stack, int count, int *order)
{
	int current;
	int candidate;
	int	i;

	current = 0;
	while (current < count)
	{
		candidate = INT_MAX;
		i = 0;
		while (i < count)
		{
			if ((current == '\0' || stack[i] > order[current - 1]) 
				&& stack[i] < candidate)
				candidate = stack[i];
			i++;
		}
		order[current] = candidate;
		current++;
	}
	return (count);
}

//currently with the logic for my algo can/should change
int	swap(int *stack_a, int *stack_b, int *lengths)
{
	int placeholder;
	int operations;

	operations = 0;
	if (lengths[0] > 1 && stack_a[0] > stack_a[1])
	{
		placeholder = stack_a[1];
		stack_a[1] = stack_a[0];
		stack_a[0] = placeholder;
		operations++;
	}
	if (lengths[1] > 1 && stack_b[0] > stack_b[1])
	{
		placeholder = stack_b[1];
		stack_b[1] = stack_b[0];
		stack_b[0] = placeholder;
		if (operations == 0)
			operations++;
	}
	return (operations);
}

void	shift_function(int *stack, char direction, int length)
{
	int placeholder;
	int i;

	i = 0;
	if (direction == 'r')
	{
		placeholder = stack[length - 1];
		i = length;
		while (i > 1)
		{
			stack[i - 1] = stack[i - 2];
			i--;
		}
		stack[i - 1] = placeholder;
	}
	if (direction == 'l')
	{
		placeholder = stack[i];
		while (i < length - 1)
		{
			stack[i] = stack[i + 1];
			i++;
		}
		stack[i] = placeholder;
	}
}

// direction r for right, l for left. 
// which either a or b or both (c). example dir_which = la or lc
int	shift(int *stack_a, int *stack_b, char *dir_which, int *length)
{
	int operations;

	operations = 0;
	if (length[0] > 1 && (dir_which[1] == 'a' || dir_which[1] == 'c'))
	{
		shift_function(stack_a, dir_which[0], length[0]);
		operations = 1;
	}
	if (length[1] > 1 && (dir_which[1] == 'b' || dir_which[1] == 'c'))
	{
		shift_function(stack_b, dir_which[0], length[1]);
		operations = 1;
	}
	return (operations);
}

int	push(int *stack_a, int *stack_b, char *which, int *length)
{
	int operations;

	operations = 0;
	if (which[0] == 'a' && length[0] > 0)
	{
		length[1] += 1;
		shift_function(stack_b, 'r', length[1]);
		stack_b[0] = stack_a[0];
		shift_function(stack_a, 'l', length[0]);
		length[0] -= 1;
		operations++;
	}
	if (which[0] == 'b' && length[1] > 0)
	{
		length[0] += 1;
		shift_function(stack_a, 'r', length[0]);
		stack_a[0] = stack_b[0];
		shift_function(stack_b, 'l', length[1]);
		length[1] -= 1;
		operations++;
	}
	return (operations);
}

int	check_if_in_a(int *stack_a, int desired, int length)
{
	int i;

	i = 0;
	while (i < length)
	{
		if (stack_a[i] == desired)
			return (1);
		i++;
	}
	return (0);
}

//find the number, see distance to l/r, move it that for l/r
int	find_then_shift(int *stack_b, int desired, int length)
{
	int distance;
	int shifts;

	if (length < 1)
		return (0);
	distance = 0;
	while (distance < length && stack_b[distance] != desired)
		distance++;
	if (distance == length)
		return (0);
	if (distance < (length / 2))
	{
		shifts = distance;
		while (distance--)
			shift_function(stack_b, 'l', length);
	}
	else
	{
		distance = length - distance;
		shifts = distance;
		while (distance--)
			shift_function(stack_b, 'r', length);
	}
	return (shifts);
}

int	push_swap(int *stack_a, int length)
{
	int	stack_b[length];
	int	total_op;
	int	desired_order[length];
	int	current_length[2];
	int i;

	//check stack validity
	total_op = 0;
	current_length[0] = det_order(stack_a, length, desired_order);
	current_length[1] = 0;
	i = 0;
	while (i < length && !check_order(stack_a, length, current_length[0]))
	{
		if (stack_a[0] == desired_order[i])
		{
			total_op += shift(stack_a, stack_b, "la", current_length);
			i++;
		}
		if (check_if_in_a(stack_a, desired_order[i], current_length[0]))
		{
			total_op += push(stack_a, stack_b, "ab", current_length);
		}
		else
		{
			total_op += fnd_thn_sh(stack_b, desired_order[i], current_length[1]);
			total_op += push(stack_a, stack_b, "ba", current_length);
		}
	}
	return (total_op);
}

*/
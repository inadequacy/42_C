/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrooks- <cbrooks-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 16:13:03 by cbrooks-          #+#    #+#             */
/*   Updated: 2026/01/29 12:41:47 by cbrooks-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	det_length(char *str)
{
	int	length;
	int	skip;

	length = 0;
	skip = 1;
	while (*str)
	{
		if (*str != ' ' && skip)
		{
			skip = 0;
			length++;
		}
		else if (*str == ' ')
			skip = 1;
		str++;
	}
	return (length);
}

char	**free_chr(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (0);
}

int	count_args(char **args)
{
	int	i;

	i = 0;
	while (args[i])
		i++;
	return (i);
}

int	determine_rank(int *stack, int length, int value)
{
	int	i;
	int	rank;

	i = 0;
	rank = 0;
	while (i < length)
	{
		if (stack[i] < value)
			rank++;
		i++;
	}
	return (rank);
}

void	normalize(int *stack, int length)
{
	int	i;
	int	*placeholder;

	placeholder = malloc(sizeof(int) * length);
	if (!placeholder)
		return ;
	i = 0;
	while (i < length)
	{
		placeholder[i] = determine_rank(stack, length, stack[i]);
		i++;
	}
	i = 0;
	while (i < length)
	{
		stack[i] = placeholder[i];
		i++;
	}
	free(placeholder);
}

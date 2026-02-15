/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrooks- <cbrooks-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 14:32:15 by cbrooks-          #+#    #+#             */
/*   Updated: 2026/01/29 14:46:28 by cbrooks-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_order(int *stack_a, int length)
{
	int	i;

	i = 0;
	while (i < length - 1)
	{
		if (stack_a[i] < stack_a[i + 1])
			i++;
		else
			return (0);
	}
	return (1);
}

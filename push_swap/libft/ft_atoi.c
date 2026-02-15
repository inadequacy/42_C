/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrooks- <	cbrooks-@student.42berlin.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 20:28:12 by cbrooks-          #+#    #+#             */
/*   Updated: 2025/11/25 20:28:12 by cbrooks-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(char chr)
{
	if (((chr == ' ') || (('\t' <= chr) && (chr <= '\r'))))
		return (1);
	return (0);
}

long	ft_atoi(const char *nptr)
{
	long	negator;
	long	result;

	negator = 1;
	result = 0;
	while (ft_isspace(*nptr) == 1 && *nptr)
		nptr++;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			negator = -1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		result *= 10;
		result += (*nptr - '0');
		nptr++;
	}
	result *= negator;
	return (result);
}

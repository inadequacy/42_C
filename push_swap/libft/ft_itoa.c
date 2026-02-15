/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrooks- <	cbrooks-@student.42berlin.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 16:18:56 by cbrooks-          #+#    #+#             */
/*   Updated: 2025/12/03 16:18:56 by cbrooks-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_intlen(long n)
{
	size_t	len;

	if (n == 0)
		return (1);
	len = 0;
	if (n < 0)
	{
		len++;
		n *= -1;
	}
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*result;
	size_t	length;
	long	number;

	number = n;
	length = ft_intlen(n);
	result = malloc(length + 1);
	if (!result)
		return (0);
	result[length] = '\0';
	if (n == 0)
		result[0] = '0';
	if (n < 0)
	{
		result[0] = '-';
		number *= -1;
	}
	while (number != 0)
	{
		result[length - 1] = ((number % 10) + '0');
		number = number / 10;
		length--;
	}
	return (result);
}

/*
#include <stdio.h>

int main(void)
{
	int one = -1212312312;
	int two = 3;
	int three = -123;
	
	printf("%s\n", ft_itoa(two));
	printf("%s\n", ft_itoa(one));
	printf("%s\n", ft_itoa(three));
}
*/
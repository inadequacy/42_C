/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrooks- <	cbrooks-@student.42berlin.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 17:06:17 by cbrooks-          #+#    #+#             */
/*   Updated: 2025/11/25 17:06:17 by cbrooks-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*src_holder;
	unsigned char	*dest_holder;

	src_holder = (unsigned char *)s1;
	dest_holder = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (n > 0)
	{
		if (*src_holder == *dest_holder)
		{
			src_holder++;
			dest_holder++;
			n--;
		}
		else if (*src_holder != *dest_holder)
			return (*src_holder - *dest_holder);
	}
	return (0);
}

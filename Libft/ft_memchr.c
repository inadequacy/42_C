/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrooks- <	cbrooks-@student.42berlin.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 16:34:04 by cbrooks-          #+#    #+#             */
/*   Updated: 2025/11/25 16:34:04 by cbrooks-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*src_holder;
	size_t			i;

	src_holder = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (src_holder[i] == (unsigned char)c)
			return ((void *)src_holder + i);
		i++;
	}
	return (0);
}

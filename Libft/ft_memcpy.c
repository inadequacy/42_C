/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrooks- <	cbrooks-@student.42berlin.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 13:23:34 by cbrooks-          #+#    #+#             */
/*   Updated: 2025/11/19 13:23:34 by cbrooks-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*dest_holder;
	unsigned char	*src_holder;

	if (!dest && !src)
		return (0);
	i = 0;
	dest_holder = (unsigned char *)dest;
	src_holder = (unsigned char *)src;
	while (i < n)
	{
		dest_holder[i] = src_holder[i];
		i++;
	}
	dest = dest_holder;
	return (dest);
}

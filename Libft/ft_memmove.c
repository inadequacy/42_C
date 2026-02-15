/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrooks- <	cbrooks-@student.42berlin.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 15:52:38 by cbrooks-          #+#    #+#             */
/*   Updated: 2025/11/19 15:52:38 by cbrooks-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*dest_holder;
	unsigned char	*src_holder;
	unsigned char	*middle_man;
	
	i = 0;
	src_holder = (unsigned char *)src;
	dest_holder = (unsigned char *)dest;
	middle_man = 0;
	if (!dest || !src)
		return (0);
	while (i < n)
	{
		middle_man[i] = src_holder[i];
		i++;
	}
	i = 0;
	while (i < n)
	{
		dest_holder[i] = middle_man[i];
		i++;
	}
	ft_memcpy(dest_holder, src_holder, i);
	return (dest);
}
*/

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*dest_holder;
	unsigned char	*src_holder;

	src_holder = (unsigned char *)src;
	dest_holder = (unsigned char *)dest;
	if (!(src_holder < dest_holder))
	{
		ft_memcpy(dest_holder, src_holder, n);
		return (dest);
	}
	while (n)
	{
		n--;
		dest_holder[n] = src_holder[n];
	}
	return (dest);
}

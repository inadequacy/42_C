/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrooks- <	cbrooks-@student.42berlin.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 15:09:27 by cbrooks-          #+#    #+#             */
/*   Updated: 2025/11/20 15:09:27 by cbrooks-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t n)
{
	size_t			i;

	i = 0;
	if (!dest || !src)
		return (0);
	if (n > 0)
	{
		while (src[i] != '\0' && i < n - 1)
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	i = ft_strlen(src);
	return (i);
}

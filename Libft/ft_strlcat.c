/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrooks- <	cbrooks-@student.42berlin.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 13:25:09 by cbrooks-          #+#    #+#             */
/*   Updated: 2025/11/21 13:25:09 by cbrooks-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t			dest_length;
	size_t			src_length;
	size_t			i;

	dest_length = ft_strlen(dest);
	src_length = ft_strlen(src);
	i = 0;
	if (n == 0)
		return (src_length);
	if (n < dest_length)
		return (src_length + n);
	while (src[i] != '\0' && (dest_length + i) < n - 1)
	{
		dest[dest_length + i] = src[i];
		i++;
	}
	dest[dest_length + i] = '\0';
	return (dest_length + src_length);
}

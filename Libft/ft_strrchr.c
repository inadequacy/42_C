/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrooks- <	cbrooks-@student.42berlin.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 13:09:47 by cbrooks-          #+#    #+#             */
/*   Updated: 2025/11/25 13:09:47 by cbrooks-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	*str;

	if (!s)
		return (0);
	i = ft_strlen(s);
	str = (char *)s;
	if ((char)c == '\0')
		return ((char *)str + i);
	while (i > 0)
	{
		i--;
		if (str[i] == (char)c)
			return ((char *)str + i);
	}
	return (0);
}

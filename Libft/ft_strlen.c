/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrooks- <	cbrooks-@student.42berlin.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 10:45:31 by cbrooks-          #+#    #+#             */
/*   Updated: 2025/12/01 10:45:31 by cbrooks-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t			i;
	unsigned char	*str_holder;

	if (!s)
		return (0);
	i = 0;
	str_holder = (unsigned char *)s;
	while (*str_holder++)
		i++;
	return (i);
}

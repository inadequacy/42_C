/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrooks- <	cbrooks-@student.42berlin.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 14:19:51 by cbrooks-          #+#    #+#             */
/*   Updated: 2025/11/27 14:19:51 by cbrooks-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	length;
	char	*placeholder;

	length = ft_strlen(s) + 1;
	placeholder = malloc(length);
	if (!placeholder)
		return (0);
	ft_strlcpy(placeholder, s, length);
	return (placeholder);
}

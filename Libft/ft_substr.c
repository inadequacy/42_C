/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrooks- <	cbrooks-@student.42berlin.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 22:09:08 by cbrooks-          #+#    #+#             */
/*   Updated: 2025/12/01 22:09:08 by cbrooks-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	str_len;
	size_t	i;

	if (!s)
		return (0);
	str_len = ft_strlen(s);
	if (str_len < start)
		return (ft_strdup(""));
	i = 0;
	if (start + len > str_len)
		len = str_len - start;
	new = (char *)malloc((len + 1) * sizeof(char));
	if (!new)
		return (0);
	while (len > 0)
	{
		new[i] = s[start + i];
		len--;
		i++;
	}
	new[i] = '\0';
	return (new);
}

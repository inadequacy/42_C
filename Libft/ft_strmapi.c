/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrooks- <	cbrooks-@student.42berlin.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 12:40:51 by cbrooks-          #+#    #+#             */
/*   Updated: 2025/12/04 12:40:51 by cbrooks-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	len;
	char			*result;

	if (!s)
		return (0);
	len = ft_strlen(s);
	result = (char *)malloc((len + 1) * sizeof(char));
	if (!result)
		return (0);
	len = 0;
	while (s[len])
	{
		result[len] = f(len, s[len]);
		len++;
	}
	result[len] = '\0';
	return (result);
}

/*
char map_capitalize_even(unsigned int i, char c)
{
    if (i % 2 == 0 && c >= 'a' && c <= 'z')
	return (c - 32);
    return (c);
}

int main(void)
{
	char *word = "bigwords";
	char *word2 = 0;
	printf("%s\n", ft_strmapi(word, map_capitalize_even));
	printf("%s\n", ft_strmapi(word2, map_capitalize_even));
}
*/
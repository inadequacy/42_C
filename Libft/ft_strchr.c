/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrooks- <	cbrooks-@student.42berlin.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 12:13:56 by cbrooks-          #+#    #+#             */
/*   Updated: 2025/11/25 12:13:56 by cbrooks-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*str;

	i = 0;
	str = (char *)s;
	while (str[i])
	{
		if (str[i] == (char)c)
			return (str + i);
		i++;
	}
	if ((char)c == '\0')
		return (str + i);
	return (0);
}

/*
#include <stdio.h>
int main(void)
{
	const char *one = "thefart";
	const char *two = "the";
	int i = 0;

	while (*one && ft_strchr(one, *two))
	{
		printf("%c", *one);
		printf("%s", "\n");
		one++;
	}
}
*/
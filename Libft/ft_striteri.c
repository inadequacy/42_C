/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrooks- <	cbrooks-@student.42berlin.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 16:18:29 by cbrooks-          #+#    #+#             */
/*   Updated: 2025/12/04 16:18:29 by cbrooks-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	len;

	if (!s)
		return ;
	len = 0;
	while (s[len])
	{
		f(len, &s[len]);
		len++;
	}
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
	ft_striteri((void*)word, map_capitalize_even);
	ft_striteri((void*)word2, map_capitalize_even);
	printf("%s\n", word);
	printf("%s\n", word2);
}
*/
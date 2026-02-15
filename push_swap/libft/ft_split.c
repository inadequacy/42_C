/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrooks- <	cbrooks-@student.42berlin.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 14:41:46 by cbrooks-          #+#    #+#             */
/*   Updated: 2025/12/02 14:41:46 by cbrooks-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_countwords(const char *s, char c)
{
	size_t	words;
	int		skip;

	words = 0;
	skip = 1;
	while (*s)
	{
		if (*s != c && skip)
		{
			skip = 0;
			words++;
		}
		else if (*s == c)
			skip = 1;
		s++;
	}
	return (words);
}

static void	ft_makewords(char **matrix, const char *s, char c, size_t words)
{
	char	*end;

	while (*s && *s == c)
		s++;
	while (words--)
	{
		end = ft_strchr(s, c);
		if (end != NULL)
		{
			*matrix = ft_substr(s, 0, end - s);
			while (*end && *end == c)
				end++;
			s = end;
		}
		else
			*matrix = ft_substr(s, 0, ft_strlen(s) + 1);
		matrix++;
	}
	*matrix = NULL;
}

char	**ft_split(const char *s, char c)
{
	size_t	words;
	char	**target;

	words = ft_countwords(s, c);
	target = malloc(sizeof(char *) * (words + 1));
	if (!target)
		return (0);
	ft_makewords(target, s, c, words);
	return (target);
}

// take the whole thing break it up into a target to return

/*
#include <stdlib.h>
#include <stdio.h>
int main (void)
{
	char *sentence = "the long    sentence had words";
	char terminator = ' ';
	char **newstuff = ft_split(sentence, terminator);
	if (!newstuff)
	printf("failed");
	else
	{
		printf("%s\n", newstuff[0]);
		printf("%s\n", newstuff[1]);
		printf("%s\n", newstuff[2]);
		printf("%s\n", newstuff[3]);
		printf("%s\n", newstuff[4]);
	}
	free(newstuff[0]);
	free(newstuff[1]);
	free(newstuff[2]);
	free(newstuff[3]);
	free(newstuff[4]);
	free(newstuff);
}

*/
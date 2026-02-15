/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrooks- <	cbrooks-@student.42berlin.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 13:49:04 by cbrooks-          #+#    #+#             */
/*   Updated: 2025/11/25 13:49:04 by cbrooks-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
       The strcmp() function compares the two strings s1 and s2.  
	   The locale is not taken into account (for a locale-          
	   aware comparison, see strcoll(3)).  
	   The comparison is done using unsigned characters. 
*/

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] == s2[i] && i < n - 1 && s1[i] && s2[i])
	{
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

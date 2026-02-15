/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrooks- <	cbrooks-@student.42berlin.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 13:05:26 by cbrooks-          #+#    #+#             */
/*   Updated: 2025/11/27 13:05:26 by cbrooks-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nelem, size_t elsize)
{
	void	*result;
	size_t	test;

	if (nelem && elsize)
	{
		test = nelem * elsize;
		if (test / nelem != elsize)
			return (0);
	}
	result = malloc(nelem * elsize);
	if (result == 0)
		return (0);
	ft_bzero(result, nelem * elsize);
	return (result);
}

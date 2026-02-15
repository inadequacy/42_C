/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrooks- <	cbrooks-@student.42berlin.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 16:56:30 by cbrooks-          #+#    #+#             */
/*   Updated: 2025/11/18 16:56:30 by cbrooks-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*temp;

	if (!n)
		return ;
	i = 0;
	temp = (unsigned char *)s;
	while (i < n)
	{
		temp[i] = '\0';
		i++;
	}
	s = temp;
}

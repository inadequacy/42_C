/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_helpers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrooks- <cbrooks-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 21:57:43 by cbrooks-          #+#    #+#             */
/*   Updated: 2026/01/05 14:22:04 by cbrooks-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_wrtlen(char c)
{
	return ((size_t)write(1, &c, 1));
}

size_t	ft_wrtstrlen(char *s)
{
	size_t	i;

	if (!s)
		s = "(null)";
	i = ft_strlen(s);
	return ((size_t)write(1, s, i));
}

size_t	ft_wrtnbrbase(size_t nbr, char *base)
{
	size_t	i;
	size_t	baselen;

	i = 0;
	baselen = ft_strlen(base);
	if (nbr >= baselen)
		i += ft_wrtnbrbase(nbr / baselen, base);
	i += ft_wrtlen(base[nbr % baselen]);
	return (i);
}

size_t	ft_wrtptr(void *ptr)
{
	size_t	i;

	i = 0;
	if (!ptr)
		return (write(1, "(nil)", 5));
	i += write(1, "0x", 2);
	i += ft_wrtnbrbase((size_t)ptr, "0123456789abcdef");
	return (i);
}

size_t	ft_wrtnbr(int nbr)
{
	size_t	i;
	size_t	placeholder;

	i = 0;
	placeholder = (size_t)nbr;
	if (nbr < 0)
	{
		i += ft_wrtlen('-');
		placeholder *= -1;
	}
	i += ft_wrtnbrbase(placeholder, "0123456789");
	return (i);
}

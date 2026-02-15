/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrooks- <cbrooks-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 11:36:36 by cbrooks-          #+#    #+#             */
/*   Updated: 2026/01/05 14:23:13 by cbrooks-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(char *s)
{
	size_t	len;

	len = 0;
	while (*s++)
		len++;
	return (len);
}

size_t	ft_options(char c, va_list args, size_t *counter)
{
	int	check;

	check = 0;
	if (c == 'c')
		check += ft_wrtlen(va_arg(args, int));
	if (c == 's')
		check += ft_wrtstrlen(va_arg(args, char *));
	if (c == 'p')
		check += ft_wrtptr(va_arg(args, void *));
	if (c == 'd' || c == 'i')
		check += ft_wrtnbr(va_arg(args, int));
	if (c == 'u')
		check += ft_wrtnbrbase(va_arg(args, unsigned int), "0123456789");
	if (c == 'x')
		check += ft_wrtnbrbase(va_arg(args, unsigned int), "0123456789abcdef");
	if (c == 'X')
		check += ft_wrtnbrbase(va_arg(args, unsigned int), "0123456789ABCDEF");
	if (c == '%')
		check += ft_wrtlen('%');
	return (*counter += check);
}

int	ft_printf(const char *s, ...)
{
	size_t	counter;
	va_list	args;

	if (!s)
		return (0);
	counter = 0;
	va_start(args, s);
	while (*s)
	{
		if (*s == '%')
		{
			s++;
			if (!ft_options(*s, args, &counter))
				return (0);
			s++;
		}
		else
		{
			counter += ft_wrtlen(*s);
			s++;
		}
	}
	va_end(args);
	return (counter);
}

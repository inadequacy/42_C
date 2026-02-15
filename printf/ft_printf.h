/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrooks- <cbrooks-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 22:02:06 by cbrooks-          #+#    #+#             */
/*   Updated: 2026/01/05 14:31:53 by cbrooks-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

/* does the thing */
int		ft_printf(const char *s, ...);

/* basic helpers */
size_t	ft_strlen(char *s);
size_t	ft_options(char c, va_list args, size_t *counter);

/* formatting, delegation, whatever u wanna call it */
size_t	ft_wrtlen(char c);
size_t	ft_wrtstrlen(char *s);
size_t	ft_wrtnbrbase(size_t nbr, char *base);
size_t	ft_wrtptr(void *ptr);
size_t	ft_wrtnbr(int nbr);

#endif
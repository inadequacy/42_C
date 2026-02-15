/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrooks- <	cbrooks-@student.42berlin.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 15:26:15 by cbrooks-          #+#    #+#             */
/*   Updated: 2026/01/11 21:49:05 by cbrooks-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

/* does the thing */
char	*get_next_line(int fd);

/* helps do the thing */
char	*det_retval(char *tmp, size_t *i, ssize_t *len_read, int fd);
char	*resize_copy(char *str, size_t cpy_len, size_t len, size_t *cnt);

#endif
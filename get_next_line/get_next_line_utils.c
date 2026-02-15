/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrooks- <	cbrooks-@student.42berlin.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 12:42:28 by cbrooks-          #+#    #+#             */
/*   Updated: 2026/01/11 21:53:49 by cbrooks-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*resize_copy(char *str, size_t cpy_len, size_t len, size_t *cnt)
{
	char	*newstr;
	size_t	i;

	newstr = (char *)malloc(len + 1);
	if (!newstr)
		return (0);
	i = 0;
	while (i < cpy_len)
	{
		newstr[i] = str[i];
		i++;
	}
	newstr[i] = '\0';
	free(str);
	*cnt = 0;
	return (newstr);
}

char	*det_retval(char *tmp, size_t *i, ssize_t *len_read, int fd)
{
	char	*ret_val;
	size_t	j;

	if (*len_read > 0)
		ret_val = (char *)malloc(*len_read + 1);
	else
		ret_val = (char *)malloc(1);
	if (!ret_val)
		return (0);
	j = 0;
	while (*len_read > 0)
	{
		if (*i == (size_t) * len_read)
		{
			*len_read = read(fd, tmp, BUFFER_SIZE);
			if (*len_read <= 0)
				break ;
			ret_val = resize_copy(ret_val, j, j + *len_read + 1, i);
		}
		ret_val[j++] = tmp[*i];
		if (tmp[(*i)++] == '\n')
			break ;
	}
	ret_val[j] = '\0';
	return (ret_val);
}

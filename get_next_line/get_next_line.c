/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrooks- <cbrooks-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 15:24:33 by cbrooks-          #+#    #+#             */
/*   Updated: 2026/01/14 15:41:45 by cbrooks-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char		tmp[BUFFER_SIZE];
	static size_t	i;
	static ssize_t	len_read;
	char			*ret_val;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (0);
	if (!len_read)
		len_read = read(fd, tmp, BUFFER_SIZE);
	if (!i)
		i = 0;
	ret_val = det_retval(tmp, &i, &len_read, fd);
	if (!ret_val || ret_val[0] == '\0')
	{
		free(ret_val);
		return (0);
	}
	return (ret_val);
}

// main for testing purposes.


#include <stdio.h>

int main (void)
{
	int	fd = open("my_file", O_RDONLY);
	
	printf("output for 1\n");
	char *str = get_next_line(fd);
	while (str)
	{
		printf("%s\n", str);
		free(str);
		str = get_next_line(fd);
	}
	free(str);
	close(fd);
	
	// char *str = get_next_line(fd);
	// printf("%s\n", str);
	// free(str);
	
	// str = get_next_line(fd);
	// printf("%s\n", str);
	// free(str);
	
	// str = get_next_line(fd);
	// printf("%s\n", str);
	// str = get_next_line(fd);
	// printf("%s\n", str);
	// str = get_next_line(fd);
	// printf("%s\n", str);
	// str = get_next_line(fd);
	// printf("%s\n", str);
	// str = get_next_line(fd);
	// printf("%s\n", str);
	// str = get_next_line(fd);
	// printf("%s\n", str);
}


/*
char	*get_next_line(int fd)
{
	static char	tmp[BUFFER_SIZE + 1];
	char		*retval;
	int			i;

	i = 0;
	retval = malloc(1);
	if (!retval)
		return (0);
	read(fd, tmp, BUFFER_SIZE);
	while (tmp[i] != '\n' && tmp[i] != '\0')
	{
		retval[i] = tmp[i];
		i++;
		retval = remalloc(retval, i + 1);
		if (tmp[i + 1] != '\0')
			get_next_line(fd);
	}
	retval[i] = '\0';
	return (retval);
}
*/

// version below working with too many lines :')

/*
char	*get_next_line(int fd)
{
	static char		tmp[BUFFER_SIZE];
	static size_t	i;
	static size_t	len_read;
	size_t			j;
	char			*ret_val;
	
	if (!len_read)
		len_read = read(fd, tmp, BUFFER_SIZE);
	if (len_read < 1)
		return (0);
	if (!i)
		i = 0;
	if (tmp[i] == '\n' && i < len_read)
		i++;
	j = 0;
	ret_val = det_retval(tmp, &i, j, &len_read, fd);
	ret_val = (char *)malloc(len_read + 1);
	if (tmp[i] == '\n')
	{
		ret_val[j] = '\n';
		ret_val[j++] = '\0';
	}
	while (tmp[i] != '\n' && len_read > 0)
	{
		if (i == len_read)
		{
			len_read = read(fd, tmp, BUFFER_SIZE);
			ret_val[j] = '\0';
			if (len_read == 0)
				break ;
			ret_val = resize_copy(ret_val, j, j + len_read);
			i = 0;
		}
		ret_val[j] = tmp[i];
		i++;
		j++;
	}
	ret_val[j] = '\0';
	return (ret_val);
}
*/
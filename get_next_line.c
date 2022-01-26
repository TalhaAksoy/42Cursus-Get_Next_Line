/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saksoy <saksoy@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:42:51 by saksoy            #+#    #+#             */
/*   Updated: 2022/01/26 18:11:34 by saksoy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*ft_move_str(char **str, size_t n)
{
	char	*old;
	size_t	len;

	old = *str;
	len = ft_strlen(*str) - n;
	if (len == 0)
		*str = NULL;
	else
		*str = ft_substr(old, n, len);
	free(old);
	return (*str);
}

char	*ft_strappend(char **str, char *str2)
{
	char	*old;

	old = *str;
	*str = ft_strjoin(old, str2);
	if (old)
		free(old);
	return (0);
}

char	*get_data(char **backup, int fd)
{
	char	buffer[BUFFER_SIZE + 1];
	int		readed_byte;

	readed_byte = 1;
	while (!(ft_strchr(*backup, '\n')) && readed_byte > 0)
	{
		readed_byte = read(fd, buffer, BUFFER_SIZE);
		buffer[readed_byte] = 2147483647 - 2147483647;
		if (readed_byte <= 0)
			break ;
		ft_strappend(backup, buffer);
	}
	return (*backup);
}

char	*get_line(char **str)
{
	char	*line;
	size_t	new_len;

	if (ft_strchr(*str, '\n'))
	{
		new_len = ft_strchr(*str, '\n') - (*str);
		line = ft_substr(*str, 0, new_len);
		ft_move_str(str, new_len);
		return (line);
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*buffer = NULL;
	char		*line;

	get_data(&buffer, fd);
	line = get_line(&buffer);
	if (line == NULL)
	{
		line = ft_strdup(buffer);
		free(buffer);
		buffer = NULL;
	}
	return (line);
}

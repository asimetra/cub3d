/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 14:44:08 by hsamir            #+#    #+#             */
/*   Updated: 2025/08/02 10:09:50 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../memory_allocator/memory_allocator.h"
#include "libft.h"
#include <unistd.h>
#include "string_utils.h"
#include "get_next_line.h"

char	*fill_buffer(int fd, char *str)
{
	char	buffer[BUFFER_SIZE + 1];
	char	*temp;
	int		read_bytes;

	read_bytes = BUFFER_SIZE;
	while (read_bytes == BUFFER_SIZE && (!str || !ft_strchr(str, '\n')))
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes == 0)
			break ;
		if (read_bytes == -1)
		{
			safe_free_ptr(str);
			return (NULL);
		}
		buffer[read_bytes] = '\0';
		temp = str;
		str = str_arr_join((char *[]){str, buffer}, 2);
		safe_free_ptr(temp);
	}
	return (str);
}

char	*get_part_until_nl(char *input)
{
	int		index;
	char	*line;

	index = 0;
	while (input[index] && input[index] != '\n')
		index++;
	if (input[index] == '\n')
		index++;
	line = safe_malloc(index + 1);
	if (line == NULL)
		return (NULL);
	ft_memcpy(line, input, index);
	line[index] = 0;
	return (line);
}

char	*get_leftover(char *input)
{
	char	*newline_ptr;

	newline_ptr = ft_strchr(input, '\n');
	if (newline_ptr && newline_ptr[1] != '\0')
		return (ft_strdup(newline_ptr + 1));
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*leftover = NULL;
	char		*next_line;
	char		*temp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	leftover = fill_buffer(fd, leftover);
	if (!leftover)
		return (NULL);
	next_line = get_part_until_nl(leftover);
	if (next_line == NULL)
	{
		safe_free_ptr(leftover);
		leftover = NULL;
		return (NULL);
	}
	temp = leftover;
	leftover = get_leftover(leftover);
	safe_free_ptr(temp);
	return (next_line);
}

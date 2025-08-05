/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 14:29:58 by hsamir            #+#    #+#             */
/*   Updated: 2025/08/05 16:00:54 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>

int	*file_descripter(void)
{
	int static	fd = -1;

	return (&fd);
}

int	open_fd(char *file)
{
	int	_fd;

	_fd = open(file, O_RDONLY);
	if (_fd != -1)
		*file_descripter() = _fd;
	return (_fd);
}

void	close_fd(char _fd)
{
	if (_fd != -1)
		close(_fd);
	*file_descripter() = -1;
}

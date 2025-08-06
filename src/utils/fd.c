/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdaban <sdaban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 14:29:58 by hsamir            #+#    #+#             */
/*   Updated: 2025/08/06 12:11:31 by sdaban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>

int	*file_descripter(void)
{
	static int	fd = -1;

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

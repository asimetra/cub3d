/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 23:21:25 by hsamir            #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2025/07/24 11:55:11 by hsamir           ###   ########.fr       */
=======
/*   Updated: 2025/08/02 10:10:15 by hsamir           ###   ########.fr       */
>>>>>>> 0acf8bb
/*                                                                            */
/* ************************************************************************** */

#include "memory_allocator/memory_allocator.h"
#include "libft.h"

/*. When exit() is called, any open file descriptors belonging to the process are closed
*/
void	safe_exit(char *message, char *line, int line_number)
{
	ft_putendl_fd("\e[1;31mError\e[34m", 2);
	ft_putstr_fd(message, 2);
	if (line)
	{
		ft_putstr_fd(" at \e[30mline:", 2);
		ft_putstr_fd(ft_itoa(line_number), 2);
		ft_putstr_fd(" \e[0m| \e[1;37m`", 2);
		ft_putstr_fd(ft_strtrim(line, "\n"), 2);
		ft_putendl_fd("`\e[0m", 2);
	}
	else
		ft_putchar_fd('\n', 2);
	safe_abort(1);
}

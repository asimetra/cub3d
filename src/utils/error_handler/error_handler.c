/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 23:21:25 by hsamir            #+#    #+#             */
/*   Updated: 2025/07/19 12:33:03 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory_allocator.h"
#include "libft.h"

/*. When exit() is called, any open file descriptors belonging to the process are closed
*/
void	safe_exit(char *message, char *line, int line_number)
{
	ft_putendl_fd("Error", 2);
	ft_putstr_fd(message, 2);
	if (line)
	{
		ft_putstr_fd(" at line: ", 2);
		ft_putstr_fd(ft_itoa(line_number), 2);
		ft_putstr_fd(" `", 2);
		ft_putstr_fd(ft_strtrim(line, "\n"), 2);
		ft_putendl_fd("`", 2);
	}
	else
		ft_putchar_fd('\n', 2);
	safe_abort(1);
}

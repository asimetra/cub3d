/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 14:07:22 by sdaban            #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2025/07/24 14:39:14 by hsamir           ###   ########.fr       */
=======
/*   Updated: 2025/08/02 15:14:36 by sdaban           ###   ########.fr       */
>>>>>>> 0acf8bb
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "element.h"
#include "string_utils.h"
<<<<<<< HEAD
#include "memory_allocator.h"
#include "limits.h"

int	is_valid_player_count(char *input)
{
	int index;
=======
#include "memory_allocator/memory_allocator.h"
#include "limits.h"
#include "cub3d.h"

int	is_valid_player_count(char *input)
{
	int	index;
>>>>>>> 0acf8bb
	int	p_count;

	index = 0;
	p_count = 0;
	while (input[index])
	{
		if (ft_strchr(PLAYER_CHR, input[index]))
			p_count++;
		index++;
	}
	return (p_count == 1 || p_count == 0);
}

int	is_valid_file_extension(char *file_path)
{
	return (ends_with(file_path, ".cub"));
}

<<<<<<< HEAD

=======
int	is_valid_position(int x, int y)
{
	t_map	*m;

	m = &game_object()->map;
	return (m->len > y && y >= 0
		&& m->lines[y].len > x && x >= 0
		&& m->lines[y].line[x] != '1');
}
>>>>>>> 0acf8bb

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdaban <sdaban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 14:07:22 by sdaban            #+#    #+#             */
/*   Updated: 2025/08/06 11:53:41 by sdaban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "string_utils.h"
#include "cub3d.h"

int	is_valid_player_count(char *input)
{
	int	index;
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

int	is_valid_position(int x, int y)
{
	t_map	*m;

	m = &game_obj()->map;
	return (m->len > y && y >= 0
		&& m->lines[y].len > x && x >= 0
		&& m->lines[y].line[x] != '1');
}

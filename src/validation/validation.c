/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdaban <sdaban@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 14:00:05 by sdaban            #+#    #+#             */
/*   Updated: 2025/07/24 16:38:19 by sdaban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "../includes/validation.h"
#include "../includes/cub3d.h"
#include "../includes/element.h"
#include "../includes/string_utils.h"
#include <limits.h>

bool	v_color_value(int value)
{
	return (value >= 0 && value <= 255);
}

bool	v_fc_colors(t_color *colors)
{
	if (!colors)
		return (false);
	return (
		v_color_value((colors->floor >> 16) & 0xFF)
		&& v_color_value((colors->floor >> 8) & 0xFF)
		&& v_color_value(colors->floor & 0xFF)
		&& v_color_value((colors->ceiling >> 16) & 0xFF)
		&& v_color_value((colors->ceiling >> 8) & 0xFF)
		&& v_color_value(colors->ceiling & 0xFF)
	);
}

bool	v_map(t_map *map)
{
	int	i;

	if (!map || !map->map || map->height == 0)
		return (false);
	i = 0;
	while (i < map->height)
	{
		if (!map->map[i] || map->map[i][0] == '\0')
			return (false);
		i++;
	}
	return (true);
}

bool	v_directions(t_map *map)
{
	int	i;
	int	j;
	int	player_count;

	if (!map || !map->map || map->height == 0)
		return (false);
	player_count = 0;
	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (map->map[i][j])
		{
			if (includes(PLAYER_CHR, map->map[i][j]))
				player_count++;
			j++;
		}
		i++;
	}
	return (player_count == 1);
}

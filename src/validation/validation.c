/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdaban <sdaban@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 14:00:05 by sdaban            #+#    #+#             */
/*   Updated: 2025/07/24 02:28:05 by sdaban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "../includes/validation.h"

bool	v_color_value(int value)
{
	return (value >= 0 && value <= 255);
}

bool	v_fc_colors(int floor, int ceiling)
{
	return (v_color_value((floor >> 16) & 0xFF)
		&& v_color_value((floor >> 8) & 0xFF)
		&& v_color_value(floor & 0xFF)
		&& v_color_value((ceiling >> 16) & 0xFF)
		&& v_color_value((ceiling >> 8) & 0xFF)
		&& v_color_value(ceiling & 0xFF));
}

bool	v_map(void)
{
	extern char	**g_map;
	extern int	g_map_height;
	int			i;

	if (!g_map || g_map_height == 0)
		return (false);
	i = 0;
	while (i < g_map_height)
	{
		if (!g_map[i] || g_map[i][0] == '\0')
			return (false);
		i++;
	}
	return (true);
}

bool	v_directions(void)
{
	extern char	**g_map;
	extern int	g_map_height;
	int			i;
	int			j;
	int			player_count;

	player_count = 0;
	i = 0;
	while (i < g_map_height)
	{
		j = 0;
		while (g_map[i][j])
		{
			if (g_map[i][j] == 'N' || g_map[i][j] == 'S'
				|| g_map[i][j] == 'E' || g_map[i][j] == 'W')
				player_count++;
			j++;
		}
		i++;
	}
	return (player_count == 1);
}

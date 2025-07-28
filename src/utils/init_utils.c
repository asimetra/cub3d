/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 17:20:36 by hsamir            #+#    #+#             */
/*   Updated: 2025/07/28 17:58:28 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "element.h"
#include "cub3d.h"
#include "memory_allocator.h"
#include "string_utils.h"

t_vector	get_player_angle(t_element_type player)
{
	if (player & T_PLAYER_N)
		return ((t_vector){.x = 0, .y = -1});
	else if (player & T_PLAYER_S)
		return ((t_vector){.x = 0, .y = 1});
	else if (player & T_PLAYER_E)
		return ((t_vector){.x = 1, .y = 0});
	else if (player & T_PLAYER_W)
		return ((t_vector){.x = -1, .y = 0});
	else
		return ((t_vector){.x = 0, .y = 0});
}

t_map	element_to_map(t_element *e)
{
	t_map_line	*map_line;
	size_t		len;
	size_t		index;

	index = 0;
	len = element_count(get_element(e, T_MAP), T_MAP);
	map_line = safe_talloc(sizeof(t_map_line) * len);
	while (index < len)
	{
		map_line[index] = (t_map_line) {
			.line = e->value.content,
			.len = e->val_len
		};
		e = e->next;
		index++;
	}
	return ((t_map) { .lines = map_line, .len = len });
}

void	init_player(t_element *e)
{
	t_element	*player;
	t_element	*map_line;

	player = get_element(e, FLAG_PLAYER);
	map_line = get_element(e, T_MAP);

	game_object()->player = (t_player) {
		.pos = (t_vector) {
			 .x = player->line - map_line->line,
			 .y = find_chars_index(player->value.content, "NSWE"),
		},
		.dir = get_player_angle(player->type)
	};
}

void	init_map(t_element *e)
{
	game_object()->map = element_to_map(get_element(e, T_MAP));
}



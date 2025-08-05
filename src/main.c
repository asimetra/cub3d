/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 00:21:31 by hsamir            #+#    #+#             */
/*   Updated: 2025/08/05 16:11:59 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../memory_allocator/memory_allocator.h"
#include "cub3d.h"
#include "element.h"
#include <unistd.h>
#include <stdio.h>
#include "validation.h"
#include "minilibx/mlx.h"
#include "string_utils.h"
#include <X11/X.h>
#include "fd.h"

const char *token_type_str(t_element_type t)
{
	switch (t) {
		case T_NORTH: return "T_NORTH";
		case T_SOUTH: return "T_SOUTH";
		case T_EAST: return "T_EAST";
		case T_WEST: return "T_WEST";
		case T_FLOOR: return "T_FLOOR";
		case T_CEIL: return "T_CEIL";
		case T_MAP: return "T_MAP";
		default: return "UNKNOWN";
	}
}

void	debug_tokens(t_element *tokens)
{
	printf("\x1b[34m┌──────────────────────────────────────────────────── DEBUG TOKENS ─────────────────────────────────────────────────────┐\x1b[0m\n");
	while(tokens)
	{
		if (tokens->type & ~(T_FLOOR | T_CEIL))
       		printf("│ \x1b[33m[%11s]\x1b[0m \x1b[32m\"%s\"\x1b[0m\n",
			token_type_str(tokens->type),
			tokens->value.content ? tokens->value.content : "(null)");
		else
			printf("│ \x1b[33m[%11s]\x1b[0m \x1b[32m\"%d,%d,%d\"\x1b[0m\n",
			token_type_str(tokens->type),
			tokens->value.color >> 16 & 0xFF,
			tokens->value.color >> 8 & 0xFF,
			tokens->value.color & 0xFF);
		tokens = tokens->next;
	}
	printf("\x1b[34m└───────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┘\x1b[0m\n");
}

t_game	*game_obj(void)
{
	static t_game	game = {0};

	return (&game);
}

int	game_loop(void *param)
{
	(void)param;
	key_event_handler();
	render();
	return (0);
}

void	cub_main(t_element *elements)
{
	register_finalizer_funct(fini_graphics);//register mlx destroy function for aborter
	init_graphics(elements);
	init_map(elements);
	init_player(elements);
	init_mlx_event_hooks();
}

int	main(int argc, char **argv)
{
	t_element	*elements;
	int			map_fd;

	if (argc != 2)
		safe_exit(USAGE_ERR, NULL, 0);
	if (!is_valid_file_extension(argv[1]))
		safe_exit(INVALID_EXT_ERR, NULL, 0);
	map_fd = open_fd(argv[1]);
	if (map_fd == -1)
		safe_exit(INVALID_FILE_ERR, NULL, 0);
	elements = parse_file(map_fd);
	close_fd(map_fd);
	debug_tokens(elements);
	cub_main(elements);
	safe_abort(0);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdaban <sdaban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 00:21:31 by hsamir            #+#    #+#             */
/*   Updated: 2025/08/06 11:54:58 by sdaban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../memory_allocator/memory_allocator.h"
#include "cub3d.h"
#include "element.h"
#include "validation.h"
#include "fd.h"

t_game	*game_obj(void)
{
	static t_game	game = {0};

	return (&game);
}

int	game_loop(void *param)
{
	(void)param;
	key_event_handler();
	game_obj()->graphics.frame_time = get_time_ms();
	render();
	return (0);
}

void	cub_main(t_element *elements)
{
	register_finalizer_funct(fini_graphics);
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
	cub_main(elements);
	safe_abort(0);
	return (0);
}

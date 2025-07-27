/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_graphics.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 09:07:00 by hsamir            #+#    #+#             */
/*   Updated: 2025/07/26 16:29:45 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"
#include "../libs/minilibx/mlx.h"
#include "element.h"
#include "memory_allocator.h"
#include "cub3d.h"
#include <stdlib.h>

void	fini_graphics(void)
{
	t_graphics	*graphics;

	graphics = &game_object()->graphics;
	if (graphics->mlx.mlx)
		mlx_destroy_window(graphics->mlx.mlx, graphics->mlx.mlx_win);
	if (graphics->textures.north)
		mlx_destroy_image(graphics->mlx.mlx, graphics->textures.north);
	if (graphics->textures.south)
		mlx_destroy_image(graphics->mlx.mlx, graphics->textures.south);
	if (graphics->textures.east)
		mlx_destroy_image(graphics->mlx.mlx, graphics->textures.east);
	if (graphics->textures.west)
		mlx_destroy_image(graphics->mlx.mlx, graphics->textures.west);
	if (graphics->mlx.mlx)
	{
		mlx_destroy_display(graphics->mlx.mlx);
		free(graphics->mlx.mlx);
	}
}

t_mlx	load_mlx_object()
{
	t_mlx	mlx;

	mlx.mlx = mlx_init();
	if (mlx.mlx == NULL)
		safe_exit("Failed to initialize MLX", NULL, 0);
	mlx.mlx_win = mlx_new_window(mlx.mlx, WIDHT, HEIGHT, TITLE);
	if (mlx.mlx_win == NULL)
		safe_exit("Failed to create MLX window", NULL, 0);
	return (mlx);
}

void	*load_image_object(t_element *e)
{
	void	*img;
	int		h;
	int		w;

	img = mlx_xpm_file_to_image(
			game_object()->graphics.mlx.mlx,
			e->value.content, &h, &w);
	if (img == NULL)
		safe_exit("Failed to load image", e->value.content, e->line);
	return (img);
}

void	init_graphics(t_element *e)
{
	t_graphics	*graphics;

	graphics = &game_object()->graphics;
	graphics->mlx = load_mlx_object();
	graphics->textures = (t_texture){
		.north = load_image_object(get_element(e, T_NORTH)),
		.south = load_image_object(get_element(e, T_SOUTH)),
		.east = load_image_object(get_element(e, T_EAST)),
		.west = load_image_object(get_element(e, T_WEST))
	};
	graphics->colors = (t_color){
		.ceiling = get_element(e, T_CEIL)->value.color,
		.floor = get_element(e, T_FLOOR)->value.color,
	};
	graphics->mlx.events = (t_event){0};
}

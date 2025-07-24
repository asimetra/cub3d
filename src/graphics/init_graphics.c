/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_graphics.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 09:07:00 by hsamir            #+#    #+#             */
/*   Updated: 2025/07/24 10:33:15 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"
#include "../libs/minilibx/mlx.h"
#include "element.h"
#include "memory_allocator.h"
#include "cub3d.h"

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
		mlx_destroy_display(graphics->mlx.mlx);
}

t_mlx	create_mlx_object()
{
	t_mlx	mlx;

	mlx.mlx = mlx_init();
	if (mlx.mlx == NULL)
		safe_abort(1);
	mlx.mlx_win = mlx_new_window(mlx.mlx, WIDHT, HEIGHT, TITLE);
	if (mlx.mlx_win == NULL)
		safe_abort(1);
	return (mlx);
}

void	*create_image_object(char *path)
{
	void	*img;

	img = mlx_xpm_file_to_image(
			game_object()->graphics.mlx.mlx,
			path, NULL, NULL);
	if (img == NULL)
		safe_abort(1);
	return (img);
}

void	init_graphics(t_element *e)
{
	t_graphics	*graphics;

	graphics = &game_object()->graphics;
	graphics->mlx = create_mlx_object();
	graphics->textures = (t_texture){
		.north = create_image_object(
			get_element(e, T_NORTH)->value.content),
		.south = create_image_object(
			get_element(e, T_SOUTH)->value.content),
		.east = create_image_object(
			get_element(e, T_EAST)->value.content),
		.west = create_image_object(
			get_element(e, T_WEST)->value.content)
	};
	graphics->colors = (t_color){
		.ceiling = get_element(e, T_CEIL)->value.color,
		.floor = get_element(e, T_FLOOR)->value.color,
	};
}

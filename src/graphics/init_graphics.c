/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_graphics.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 09:07:00 by hsamir            #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2025/07/24 11:38:41 by hsamir           ###   ########.fr       */
=======
/*   Updated: 2025/08/02 10:11:13 by hsamir           ###   ########.fr       */
>>>>>>> 0acf8bb
/*                                                                            */
/* ************************************************************************** */

#include "config.h"
#include "../libs/minilibx/mlx.h"
#include "element.h"
<<<<<<< HEAD
#include "memory_allocator.h"
=======
#include "memory_allocator/memory_allocator.h"
>>>>>>> 0acf8bb
#include "cub3d.h"
#include <stdlib.h>

void	fini_graphics(void)
{
	t_graphics	*graphics;

	graphics = &game_object()->graphics;
	if (graphics->mlx.mlx)
		mlx_destroy_window(graphics->mlx.mlx, graphics->mlx.mlx_win);
<<<<<<< HEAD
	if (graphics->textures.north)
		mlx_destroy_image(graphics->mlx.mlx, graphics->textures.north);
	if (graphics->textures.south)
		mlx_destroy_image(graphics->mlx.mlx, graphics->textures.south);
	if (graphics->textures.east)
		mlx_destroy_image(graphics->mlx.mlx, graphics->textures.east);
	if (graphics->textures.west)
		mlx_destroy_image(graphics->mlx.mlx, graphics->textures.west);
=======
	if (graphics->textures.north.ptr)
		mlx_destroy_image(graphics->mlx.mlx, graphics->textures.north.ptr);
	if (graphics->textures.south.ptr)
		mlx_destroy_image(graphics->mlx.mlx, graphics->textures.south.ptr);
	if (graphics->textures.east.ptr)
		mlx_destroy_image(graphics->mlx.mlx, graphics->textures.east.ptr);
	if (graphics->textures.west.ptr)
		mlx_destroy_image(graphics->mlx.mlx, graphics->textures.west.ptr);
	if (graphics->frame.ptr)
		mlx_destroy_image(graphics->mlx.mlx, graphics->frame.ptr);
>>>>>>> 0acf8bb
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
<<<<<<< HEAD
	mlx.mlx_win = mlx_new_window(mlx.mlx, WIDHT, HEIGHT, TITLE);
=======
	mlx.mlx_win = mlx_new_window(mlx.mlx, WIDTH, HEIGHT, TITLE);
>>>>>>> 0acf8bb
	if (mlx.mlx_win == NULL)
		safe_exit("Failed to create MLX window", NULL, 0);
	return (mlx);
}

<<<<<<< HEAD
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
=======
t_image	load_frame_object()
{
	t_image	img;

	img = (t_image) {0};
	img.ptr = mlx_new_image(
		game_object()->graphics.mlx.mlx,
		WIDTH,
		HEIGHT
	);
	if (img.ptr == NULL)
		safe_exit("Failed to load frame", NULL, 0);
	img.data_addr = mlx_get_data_addr(
		img.ptr,
		&img.bits_per_pixel,
		&img.size_line,
		&img.endian
	);
	return (img);
}

t_image	load_image_object(t_element *e)
{
	t_image	img;

	img = (t_image) {0};
	img.ptr = mlx_xpm_file_to_image(
		game_object()->graphics.mlx.mlx,
		e->value.content,
		&img.width,
		&img.height
	);
	if (img.ptr == NULL)
		safe_exit("Failed to load image", e->value.content, e->line);
	img.data_addr = mlx_get_data_addr(
		img.ptr,
		&img.bits_per_pixel,
		&img.size_line,
		&img.endian
	);
>>>>>>> 0acf8bb
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
<<<<<<< HEAD
=======
	graphics->frame = load_frame_object();
>>>>>>> 0acf8bb
	graphics->colors = (t_color){
		.ceiling = get_element(e, T_CEIL)->value.color,
		.floor = get_element(e, T_FLOOR)->value.color,
	};
<<<<<<< HEAD
=======
	graphics->mlx.events = (t_event){0};
>>>>>>> 0acf8bb
}

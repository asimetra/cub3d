/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 22:32:03 by hsamir            #+#    #+#             */
/*   Updated: 2025/08/02 11:38:59 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "element.h"
#include "cub3d.h"
#include <stdio.h>
#include <unistd.h>
#include "math.h"
#include "config.h"
#include "validation.h"
#include "types.h"
#include "minilibx/mlx.h"


/*
	value/size -> [0, 1],
	2 × (value/size) – 1 -> [-1, 1]
*/
t_vector	get_ray_direction(int x, t_vector camera, t_vector dir)
{
	double	offset;

	offset = 2 * x / (double)WIDTH - 1;
	return ((t_vector) {
		.x = dir.x + camera.x * offset,
		.y = dir.y + camera.y * offset
	});
}

double	get_wall_x(t_ray ray)
{
	double	wall_x;

	if (ray.hit_side == SIDE_X)
		wall_x = ray.origin.y + ray.perp_dist * ray.dir.y;
	else
		wall_x = ray.origin.x + ray.perp_dist * ray.dir.x;
	return ((wall_x - floor(wall_x)));
}

void	init_column_info(t_column_info *c, int x)
{
	c->x = x;
	c->wall_height = (HEIGHT / c->ray.perp_dist); // h = orginal_h * (1 / perp)
	c->wall_start = (HEIGHT / 2) - (c->wall_height) / 2;
	if (c->wall_start < 0)
		c->wall_start = 0;
	c->wall_end = (HEIGHT / 2) + (c->wall_height) / 2;
	if (c->wall_end >= HEIGHT)
		c->wall_end = HEIGHT - 1;
	c->texture = get_wall_texture(c->ray.hit_side, c->ray.dir);
	c->tex.x =	get_wall_x(c->ray) * c->texture->width;
	c->step_y = c->texture->height / c->wall_height;
	c->tex.y = (c->wall_start - HEIGHT / 2 + c->wall_height / 2) * c->step_y;

}

void	render(void)
{
	t_game			*g;
	t_column_info	column_info;
	int				x;

	g = game_object();
	x = 0;
	while (x < WIDTH)
    {
		column_info.ray = (t_ray){
		.dir = get_ray_direction(x, g->player.camera, g->player.dir),
		.hit_side = 0,
		.origin = g->player.pos
		};
		do_dda(&column_info.ray);
        init_column_info(&column_info, x);
		draw_line_to_frame(&column_info);
		x++;
	}
	mlx_put_image_to_window(g->graphics.mlx.mlx, g->graphics.mlx.mlx_win, g->graphics.frame.ptr, 0, 0);
}

int game_loop(void *param)
{
	(void)param;
	//render_frame();
	key_event_handler();
	render();
	return (0);
}

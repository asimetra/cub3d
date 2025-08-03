/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 22:32:03 by hsamir            #+#    #+#             */
/*   Updated: 2025/08/03 18:51:56 by hsamir           ###   ########.fr       */
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



double	get_wall_x(t_ray ray)
{
	double	wall_x;

	if (ray.hit_side == SIDE_X)
		wall_x = ray.origin.x + ray.perp_dist * ray.dir.x;
	else
		wall_x = ray.origin.y + ray.perp_dist * ray.dir.y;

	return ((wall_x - floor(wall_x)));
}

void	init_column_info(t_column *c, int x)
{
	c->x = x;
	c->wall_height = (HEIGHT / (c->ray.perp_dist)); // h = orginal_h * (1 / perp) k = 1 * 1 -> k = wall_prep * real_wall_height 
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
	t_game		*g;
	t_column	col;
	int			x;

	x = 0;
	g = game_object();
	while (x < WIDTH)
    {
		col.ray = cast_ray(x);
        init_column_info(&col, x);
		draw_line_to_frame(&col);
		x++;
	}
	mlx_put_image_to_window(
		g->graphics.mlx.mlx, 
		g->graphics.mlx.mlx_win,
		g->graphics.frame.ptr,
		0, 0);
}

int game_loop(void *param)
{
	(void)param;
	//render_frame();
	key_event_handler();
	render();
	return (0);
}


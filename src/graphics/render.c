/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 22:32:03 by hsamir            #+#    #+#             */
/*   Updated: 2025/08/04 19:38:39 by hsamir           ###   ########.fr       */
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

double	get_wall_x(t_ray ray, t_vector pos)
{
	double	wall_x;

	if (ray.hit_side == SIDE_X)
		wall_x = pos.y + ray.perp_dist * ray.dir.y;
	else
		wall_x = pos.x + ray.perp_dist * ray.dir.x;
	return ((wall_x - floor(wall_x)));
}
/*
	wall_height =>  h = orginal_h * (1 / perp)   => k = 1 * 1 -> k = wall_prep * real_wall_height
*/
t_column	init_column_info(int x, t_ray ray, t_game *g)
{
	int		wall_height;
	int		wall_start;
	int		wall_end;
	double	step_y;
	t_image	*texture;
	
	wall_height = HEIGHT / ray.perp_dist;
	wall_start = HEIGHT / 2 - wall_height / 2;
	if (wall_start < 0)
		wall_start = 0;
	wall_end = HEIGHT / 2 + wall_height / 2;
	if (wall_end >= HEIGHT)
		wall_end = HEIGHT - 1;
	texture = get_wall_texture(ray.hit_side, ray.dir);
	step_y = 1.0 * texture->height / wall_height;
	return ((t_column){
		.x = x,
		.wall_height = wall_height,
		.wall_start = wall_start,
		.wall_end = wall_end,
		.texture = texture,
		.step_y = step_y,
		.tex.x = get_wall_x(ray, g->player.pos) * texture->width,
		.tex.y = (wall_start - (HEIGHT / 2 - wall_height / 2)) * step_y,
	});
}

void	render(void)
{
	int			x;
	t_game		*g;
	t_ray		ray;
	t_column	col;

	x = 0;
	g = game_object();
	while (x < WIDTH)
    {
		ray = cast_ray(x);
        col = init_column_info(x, ray, g);
		draw_line_to_frame(&col);
		x++;
	}
	mlx_put_image_to_window(
		g->graphics.mlx.mlx,
		g->graphics.mlx.mlx_win,
		g->graphics.frame.ptr,
		0, 0);
}


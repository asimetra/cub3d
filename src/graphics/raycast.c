/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdaban <sdaban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 00:30:56 by hsamir            #+#    #+#             */
/*   Updated: 2025/08/06 11:37:12 by sdaban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "types.h"
#include "graphics.h"

char	get_map_tile(int x, int y)
{
	t_map	*m;

	m = &game_obj()->map;
	if (m->len > y && y >= 0 && m->lines[y].len > x && x >= 0)
		return (m->lines[y].line[x]);
	return ('\0');
}

double	do_dda(t_ray *r)
{
	while (1)
	{
		if (r->side_dist.x < r->side_dist.y)
		{
			r->side_dist.x += r->delta.x;
			r->map.x += r->step.x;
			r->hit_side = SIDE_X;
		}
		else
		{
			r->side_dist.y += r->delta.y;
			r->map.y += r->step.y;
			r->hit_side = SIDE_Y;
		}
		if (get_map_tile(r->map.x, r->map.y) == '1')
			break ;
	}
	return (calc_perp_dist(r->hit_side, r->side_dist, r->delta));
}

t_ray	cast_ray(int x)
{
	t_game	*g;
	t_ray	ray;

	g = game_obj();
	ray.dir = calc_ray_dir(x, g->player.camera, g->player.dir);
	ray.hit_side = 0;
	ray.map = (t_point){g->player.pos.x, g->player.pos.y};//ensure that is this var needed?
	ray.delta = calc_delta_of(ray.dir);
	ray.step = calc_step_of(ray.dir);
	ray.side_dist = calc_side_dist(ray.delta, g->player.pos, ray.step);
	ray.perp_dist = do_dda(&ray);
	return (ray);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 00:30:56 by hsamir            #+#    #+#             */
/*   Updated: 2025/08/03 18:52:50 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "types.h"
#include "config.h"
#include <math.h>

char	get_map_tile(int x, int y)
{
	t_map	*m;

	m = &game_object()->map;
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
	return(cal_prep_dist(*r));
}

t_ray	cast_ray(int x)
{
	t_game	*g;
	t_ray	ray;
	
	g = game_object();
	ray = (t_ray){
		.dir = cal_ray_dir(x, g->player.camera, g->player.dir),
		.hit_side = 0,
		.origin = g->player.pos,
	};
	ray.map = (t_point){ray.origin.x, ray.origin.y};
	ray.delta = cal_delta(ray.dir);
	ray.side_dist = cal_side_dist(ray);
	ray.step = cal_step(ray.dir);
	ray.perp_dist = do_dda(&ray);
	return (ray);
}






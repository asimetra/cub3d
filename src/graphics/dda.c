/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 00:30:56 by hsamir            #+#    #+#             */
/*   Updated: 2025/08/02 11:37:38 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "types.h"
#include "math.h"

t_vector	get_delta(t_vector ray)
{
	t_vector	delta;

	if (ray.x == 0)
		delta.x = 1e30;
	else
		delta.x = fabs(1 / ray.x); // delta_x = sqrt(1 + pow(ray.y/ray.x, 2));
	if (ray.y == 0)
		delta.y = 1e30;
	else
		delta.y = fabs(1 / ray.y); // delta_y = sqrt(1 + pow(ray.x/ray.y, 2));
	return (delta);
}

t_point	get_step(t_vector ray)
{
	return ((t_point) {
		.x = 2 * (ray.x > 0) - 1,
		.y = 2 * (ray.y > 0) - 1
	});
}

t_vector	get_side_dist(t_point step, t_vector delta, t_point map, t_vector p)
{
	t_vector	side_dist;

	if (step.x < 0)
		side_dist.x = (p.x - map.x) * delta.x;
	else
		side_dist.x = (map.x + 1 - p.x) * delta.x;
	if (step.y < 0)
		side_dist.y = (p.y - map.y) * delta.y;
	else
		side_dist.y = (map.y + 1 - p.y) * delta.y;
	return (side_dist);
}

double	get_side_distance(t_vector side_dist, t_vector delta, int side)
{
	if (side == SIDE_X)
		return (side_dist.x - delta.x);
	else
		return (side_dist.y - delta.y);
}

char	get_map_tile(int x, int y)
{
	t_map	*m;

	m = &game_object()->map;
	if (m->len > y && y >= 0 && m->lines[y].len > x && x >= 0)
		return (m->lines[y].line[x]);
	return ('\0');
}

void	do_dda(t_ray *ray)
{
	t_vector	delta;
	t_vector	side_dist;
	t_point		map;
	t_point		step;

	delta = get_delta(ray->dir);
	step = get_step(ray->dir);
	map = (t_point){ray->origin.x, ray->origin.y};
	side_dist = get_side_dist(step, delta, map, ray->origin);
	while (1)
	{
		if (side_dist.x < side_dist.y)
		{
			side_dist.x += delta.x;
			map.x += step.x;
			ray->hit_side = SIDE_X;
		}
		else
		{
			side_dist.y += delta.y;
			map.y += step.y;
			ray->hit_side = SIDE_Y;
		}
		if (get_map_tile(map.x, map.y) == '1')
			break ;
	}
	ray->perp_dist = get_side_distance(side_dist, delta, ray->hit_side);
}



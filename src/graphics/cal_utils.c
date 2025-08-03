/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cal_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 18:14:56 by hsamir            #+#    #+#             */
/*   Updated: 2025/08/03 20:19:16 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "math.h"
#include "cub3d.h"
#include "config.h"

t_vector	cal_delta(t_vector ray)
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

/*
	origin is player vector
*/
t_vector	cal_side_dist(t_ray r)
{
	t_vector	side_dist;

	if (r.step.x < 0)
		side_dist.x = (r.origin.x - r.map.x) * r.delta.x;
	else
		side_dist.x = (r.map.x + 1 - r.origin.x) * r.delta.x;
	if (r.step.y < 0)
		side_dist.y = (r.origin.y - r.map.y) * r.delta.y;
	else
		side_dist.y = (r.map.y + 1 - r.origin.y) * r.delta.y;
	return (side_dist);
}

double	cal_prep_dist(t_ray r)
{
	if (r.hit_side == SIDE_X)
		return (r.side_dist.x - r.delta.x);
	else
		return (r.side_dist.y - r.delta.y);
}

t_point	cal_step(t_vector ray)
{
	return ((t_point){
		.x = 2 * (ray.x > 0) - 1,
		.y = 2 * (ray.y > 0) - 1
	});
}

/*
	value/size -> [0, 1],
	2 × (value/size) – 1 -> [-1, 1]
*/
t_vector	cal_ray_dir(int x, t_vector camera, t_vector dir)
{
	double	offset;

	offset = 2 * x / (double)WIDTH - 1;
	return ((t_vector) {
		.x = dir.x + camera.x * offset,
		.y = dir.y + camera.y * offset
	});
}

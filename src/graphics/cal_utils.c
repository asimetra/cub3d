/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cal_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdaban <sdaban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 18:14:56 by hsamir            #+#    #+#             */
/*   Updated: 2025/08/06 11:56:43 by sdaban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "math.h"
#include "config.h"
#include "graphics.h"

t_vector	calc_ray_dir(
	int x,
	t_vector camera,
	t_vector dir)
{
	double	offset;

	offset = 2 * x / (double)WIDTH - 1;
	return ((t_vector){
		.x = dir.x + camera.x * offset,
		.y = dir.y + camera.y * offset
	});
}

t_vector	calc_delta_of(t_vector ray)
{
	t_vector	delta;

	if (ray.x == 0)
		delta.x = 1e30;
	else
		delta.x = fabs(1 / ray.x);
	if (ray.y == 0)
		delta.y = 1e30;
	else
		delta.y = fabs(1 / ray.y);
	return (delta);
}

t_point	calc_step_of(t_vector ray)
{
	return ((t_point){
		.x = 2 * (ray.x > 0) - 1,
		.y = 2 * (ray.y > 0) - 1
	});
}

t_vector	calc_side_dist(t_vector delta, t_vector player, t_point step)
{
	t_vector	side_dist;
	t_point		coord;

	coord = (t_point){.x = (int)player.x, .y = (int)player.y};
	if (step.x < 0)
		side_dist.x = (player.x - coord.x) * delta.x;
	else
		side_dist.x = (coord.x + 1 - player.x) * delta.x;
	if (step.y < 0)
		side_dist.y = (player.y - coord.y) * delta.y;
	else
		side_dist.y = (coord.y + 1 - player.y) * delta.y;
	return (side_dist);
}

double	calc_perp_dist(int hit_side, t_vector side_dist, t_vector delta)
{
	if (hit_side == SIDE_X)
		return (side_dist.x - delta.x);
	else
		return (side_dist.y - delta.y);
}

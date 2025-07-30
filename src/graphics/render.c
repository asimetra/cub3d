/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 22:32:03 by hsamir            #+#    #+#             */
/*   Updated: 2025/07/30 16:53:03 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "element.h"
#include "cub3d.h"
#include <stdio.h>
#include <unistd.h>
#include "math.h"
#include "config.h"
#include "validation.h"
unsigned int fps ()
{
	unsigned long current_time;
	unsigned long *last_frame_time;
	unsigned int fps;

	current_time = current_time_ms();
	last_frame_time = &game_object()->graphics.frame_time;
	fps = 1000 / (current_time - *last_frame_time);
	*last_frame_time = current_time;
	return fps;
}

int game_loop(void *param)
{
	(void)param;
	// printf("FPS: %u\n", fps());
	return (0);
}

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


double	do_dda(t_vector p, t_vector ray)
{

	double	delta_x;
	double	delta_y;
	int		step_x;
	int		step_y;
	double	side_dist_x;
	double	side_dist_y;
	int map_x;
	int map_y;


	map_x = p.x;
	map_y = p.y;

	delta_x = sqrt(1 + pow(ray.y/ray.x, 2));
	delta_y = sqrt(1 + pow(ray.x/ray.y, 2)); // 1/ray.x

	step_x = ray.x > 0 ? 1 : -1;
	step_y = ray.y > 0 ? 1 : -1 ;

	side_dist_x = step_x < 0 ? (p.x - map_x) * delta_x: (map_x + 1 - p.x) * delta_x;
	side_dist_y = step_y < 0 ? (p.y - map_y) * delta_y: (map_y + 1 - p.y) * delta_y;

    int side = 0;
	while (1)
	{
		if (side_dist_x < side_dist_y)
		{
			map_x+= step_x;
			side_dist_x +=  delta_x;
			side = 0;
		}
		else
		{
			map_y += step_y;
			side_dist_y += delta_y;
			side = 1;
		}
		if (game_object()->map.lines[map_y].line[map_x] == '1')
			break;
	}

	if (side==0)
    	return  side_dist_x - delta_x;
     else
	 	return side_dist_y - delta_y;
}

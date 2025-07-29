/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 22:32:03 by hsamir            #+#    #+#             */
/*   Updated: 2025/07/29 13:34:47 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "element.h"
#include "cub3d.h"
#include <stdio.h>
#include <unistd.h>
#include "math.h"
#include "config.h"

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

t_vector	get_ray_direction(int x, t_vector camera, t_vector dir)
{
	double offset;

	offset = 2 * x / (double)WIDTH - 1;
	return ((t_vector) {
		.x = dir.x + camera.x * offset,
		.y = dir.y + camera.y * offset
	});
}


// #include "config.h"
// void render()
// {
// 	int x;

// 	x = 0;
// 	while (x < WIDTH)
// 	{
// 		get_ray();
// 		draw_line(x);
// 		x++;
// 	}
// }

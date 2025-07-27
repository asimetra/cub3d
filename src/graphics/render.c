/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 22:32:03 by hsamir            #+#    #+#             */
/*   Updated: 2025/07/26 15:41:29 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "element.h"
#include "cub3d.h"
#include <stdio.h>
#include <unistd.h>

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


// #include "config.h"
// void render()
// {
// 	int x;

// 	x = 0;
// 	while (x < HEIGHT)
// 	{
// 		draw_line(x);
// 		x++;
// 	}
// }

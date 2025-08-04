/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 16:13:03 by hsamir            #+#    #+#             */
/*   Updated: 2025/08/04 20:56:32 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "../memory_allocator/memory_allocator.h"
#include "config.h"
#include <math.h>
#include "validation.h"
#include "types.h"
#include <stdio.h>

int	key_press_hook(int keycode, t_event *event)
{
	if (keycode == E_UP)
		event->up = 1;
	else if (keycode == E_DOWN)
		event->down = 1;
	else if (keycode == E_LEFT)
		event->left = 1;
	else if (keycode == E_RIGHT)
		event->right = 1;
	else if (keycode == E_LEFT_ARROW)
		event->left_arrow = 1;
	else if (keycode == E_RIGHT_ARROW)
		event->right_arrow = 1;
	else if (keycode == E_ESC)
		event->esc = 1;
	return (0);
}

int	key_release_hook(int keycode, t_event *event)
{
	if (keycode == E_UP)
		event->up = 0;
	else if (keycode == E_DOWN)
		event->down = 0;
	else if (keycode == E_LEFT)
		event->left = 0;
	else if (keycode == E_RIGHT)
		event->right = 0;
	else if (keycode == E_LEFT_ARROW)
		event->left_arrow = 0;
	else if (keycode == E_RIGHT_ARROW)
		event->right_arrow = 0;
	else if (keycode == E_ESC)
		event->esc = 0;
	return (0);
}

/*
	LEFT_ARROW -> {
		x′=cos(φ-θ) = cosφ * cosθ + sinφ * sinθ = x * cosθ + y * sinθ,si
		y′=sin(φ-θ) = sinφ * cosθ - cosφ * sinθ= x * sinθ - y * cosθ.
	},
	RIGHT_ARROW -> {
		x′=cos(φ+θ) = cosφ * cosθ - sinφ * sinθ = x * cosθ - y * sinθ,
		y′=sin(φ+θ) = sinφ * cosθ + cosφ * sinθ= x * sinθ + y * cosθ.
	}
		cos is a even function, sin is an odd function so that,
		 * cos(-θ) = cos(θ) and sin(-θ) = -sin(θ).
	we can use one formule for both left and right arrow keys,
	{
		x′ = x * cos(rotation_speed) - y * sin(rotation_speed),
		y′ = x * sin(rotation_speed) + y * cos(rotation_speed)
	}
*/
t_vector	set_rotation(t_vector dir, double angle)
{
	return ((t_vector){
		.x = dir.x * cos(angle) - dir.y * sin(angle),
		.y = dir.x * sin(angle) + dir.y * cos(angle)
	});
}

t_vector	set_position(t_vector pos, t_vector dir)
{
	t_vector	new_pos;

	new_pos = (t_vector){
		.x = pos.x + dir.x * SPEED,
		.y = pos.y + dir.y * SPEED
	};
	if (!is_valid_position(new_pos.x, new_pos.y))
		return (pos);
	return (new_pos);
}

/*
	UP  -> {x,-y},
	DOWN  -> {-x,y} rotate 180 degrees,
	LEFT  -> {-y,-x} rotate 90 degrees,
	RIGHT -> {y,x} rotate -90 degrees,

*/
void	key_event_handler(void)
{
	t_player	*p;
	t_event		*event;

	p = &game_obj()->player;
	event = &game_obj()->graphics.mlx.events;
	if (event->esc)
		safe_abort(0);
	if (event->up)
		p->pos = set_position(p->pos, (t_vector){p->dir.x, p->dir.y});
	if (event->down)
		p->pos = set_position(p->pos, (t_vector){-p->dir.x, -p->dir.y});
	if (event->left)
		p->pos = set_position(p->pos, (t_vector){p->dir.y, -p->dir.x});
	if (event->right)
		p->pos = set_position(p->pos, (t_vector){-p->dir.y, p->dir.x});
	if (event->left_arrow)
		p->dir = set_rotation(p->dir, -ROTATION_ANGLE);
	if (event->right_arrow)
		p->dir = set_rotation(p->dir, ROTATION_ANGLE);
	if (event->left_arrow || event->right_arrow)
		p->camera = (t_vector){
			.x = -p->dir.y * tan(FOV * PI / 360), /*XXX FOV/2 * PI/180 */
			.y = p->dir.x * tan(FOV * PI / 360)
		};
	printf("Player Position: (%.2f, %.2f)   Dir: (%.2f, %.2f)\n", p->pos.y, p->pos.x, p->dir.x, p->dir.y);
}

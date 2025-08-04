/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_events.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 12:09:39 by hsamir            #+#    #+#             */
/*   Updated: 2025/08/04 20:56:32 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../memory_allocator/memory_allocator.h"
#include "cub3d.h"
#include "minilibx/mlx.h"
#include <X11/X.h>

void	init_mlx_event_hooks(void)
{
	t_mlx	*mlx;

	mlx = &game_obj()->graphics.mlx;
	mlx_hook(mlx->mlx_win, KeyPress, KeyPressMask, key_press_hook,
		&mlx->events);
	mlx_hook(mlx->mlx_win, KeyRelease, KeyReleaseMask, key_release_hook,
		&mlx->events);
	mlx_loop_hook(mlx->mlx, game_loop, NULL);
	mlx_hook(mlx->mlx_win, DestroyNotify, StructureNotifyMask, safe_abort,
		NULL);
	mlx_loop(mlx->mlx);
}

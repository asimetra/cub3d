/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_events.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 12:09:39 by hsamir            #+#    #+#             */
/*   Updated: 2025/07/27 14:03:44 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <X11/X.h>
#include "cub3d.h"
#include "memory_allocator.h"
#include "minilibx/mlx.h"

void	init_mlx_event_hooks(void)
{
	t_mlx	*mlx;

	mlx = &game_object()->graphics.mlx;
	mlx_hook(mlx->mlx_win, KeyPress, KeyPressMask, key_press_hook, &mlx->events);
	mlx_hook(mlx->mlx_win, KeyRelease, KeyReleaseMask, key_release_hook, &mlx->events);
	mlx_loop_hook(mlx->mlx, &render_windows, NULL);
	mlx_hook(mlx->mlx_win, 17, 1 << 17L, safe_abort, NULL);
	mlx_loop(mlx->mlx);
}

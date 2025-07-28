/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 15:26:09 by hsamir            #+#    #+#             */
/*   Updated: 2025/07/28 17:45:57 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "minilibx/mlx.h"
#include "math.h"
#include <stdlib.h>
#include "config.h"

void draw_line(t_vector start, t_vector end, int color)
{
    int dx = end.x - start.x;
    int dy = end.y - start.y;
    int steps = fmax(abs(dx), abs(dy));

    float x_inc = (float)dx / steps;
    float y_inc = (float)dy / steps;

    float x = start.x;
    float y = start.y;

    for (int i = 0; i <= steps; i++) {
        mlx_pixel_put(game_object()->graphics.mlx.mlx, game_object()->graphics.mlx.mlx_win, (int)x, (int)y, color);
        x += x_inc;
        y += y_inc;
    }
}
# define TS 64

#include <stdio.h>
int draw_map(t_map *map)
{
    int x, y;
    t_game *game = game_object();

    for (y = 0; y < map->len; y++)
    {
        for (x = 0; x < map->lines[y].len; x++)
        {
            if (map->lines[y].line[x] == '1') // Assuming '1' represents a wall
            {
               mlx_put_image_to_window(game->graphics.mlx.mlx, game->graphics.mlx.mlx_win, game->graphics.textures.west, x * TS, y * TS); // Draw wall texture
            }
        }
    }
    return 0;
}


int render_windows(void* pr)
{
	(void)pr;
    key_event_handler();
	t_game *game = game_object();
	t_vector start = {game->player.pos.x*TS + TS/2, game->player.pos.y*TS + TS/2};
	t_vector end = {start.x + game->player.dir.x  * 100, start.y + game->player.dir.y * 100};

    mlx_clear_window(game->graphics.mlx.mlx, game->graphics.mlx.mlx_win);
	// Draw a simple line across the screen
    // if (start.x < 0 || start.x >= WIDHT  * 64 || start.y < 0 || start.y >= HEIGHT * 64 ||
    //     end.x < 0 || end.x >= WIDHT  * 64 || end.y < 0 || end.y >= HEIGHT * 64 )
    // {
    //     return -1; // Out of bounds
    // }
        draw_map(&game->map);

	draw_line(start, end, 0xFFFFFF); // White color
    mlx_put_image_to_window(game->graphics.mlx.mlx, game->graphics.mlx.mlx_win, game->graphics.textures.north, (int)start.x - TS/2, (int)start.y - TS/2); // Draw a red pixel at (100, 100)
	// You can add more drawing logic here
	// For example, drawing walls, sprites, etc.
    return 0;
}

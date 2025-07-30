/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 15:26:09 by hsamir            #+#    #+#             */
/*   Updated: 2025/07/30 16:28:06 by hsamir           ###   ########.fr       */
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

int draw_wall(double height, int x)
{
    double start = HEIGHT/2 - height/2;
    double end = HEIGHT/2 + height/2;

    if (start < 0)       start = 0;
if (end   >= HEIGHT) end   = HEIGHT-1;
    for (int y = 0; y < HEIGHT; y++)
    {
        if (y < start)
            mlx_pixel_put(game_object()->graphics.mlx.mlx, game_object()->graphics.mlx.mlx_win, x, y, game_object()->graphics.colors.ceiling);
        else if (y > end)
            mlx_pixel_put(game_object()->graphics.mlx.mlx, game_object()->graphics.mlx.mlx_win, x, y, game_object()->graphics.colors.floor);
        else
            mlx_pixel_put(game_object()->graphics.mlx.mlx, game_object()->graphics.mlx.mlx_win, x, y, 0x555555);
    }
    return 0;
}


int render_windows(void* pr)
{
	(void)pr;

	t_game *game = game_object();
    (void)game;
	// t_vector start = {game->player.pos.x*TS + TS/2, game->player.pos.y*TS + TS/2};
	// t_vector end = {start.x + game->player.dir.x  * TS, start.y + game->player.dir.y * TS};
    // t_vector end2 = {end.x + (game->player.camera.x) * TS, end.y + (game->player.camera.y) * TS};

	// Draw a simple line across the screen
    // if (start.x < 0 || start.x >= WIDHT  * 64 || start.y < 0 || start.y >= HEIGHT * 64 ||
    //     end.x < 0 || end.x >= WIDHT  * 64 || end.y < 0 || end.y >= HEIGHT * 64 )
    // {
    //     return -1; // Out of bounds
    // }
    // draw_map(&game->map);
   key_event_handler();
	// draw_line(start, end, 0xFFFFFF); // White color
    for (int x = 0; x < WIDTH; x++)
    {
        t_vector ray = get_ray_direction(x, game->player.camera, game->player.dir);
        double distance = do_dda(game->player.pos, ray);
        printf("%f\n", distance);
        draw_wall((HEIGHT/distance), x);

        // draw_line(start,
        //      (t_vector){start.x + ray.x * TS, start.y + ray.y * TS},
        //      0xa1a1a1); // White color
    }
    // mlx_clear_window(game->graphics.mlx.mlx, game->graphics.mlx.mlx_win);

	// You can add more drawing logic here
	// For example, drawing walls, sprites, etc.
    return 0;
}

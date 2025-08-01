/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 11:34:53 by hsamir            #+#    #+#             */
/*   Updated: 2025/08/01 19:29:41 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx/mlx.h"
#include "cub3d.h"
#include "libft.h"
#include "config.h"

void	put_pixel_to_frame(int x, int y, int pixel)
{
	t_image	*f;
	int		byte_per_pixel;
	char	*addr;

	f = &game_object()->graphics.frame;
	byte_per_pixel = f->bits_per_pixel / 8;
	addr = f->data_addr + f->size_line * y + byte_per_pixel * x;
	ft_memcpy(addr, &pixel, sizeof(pixel));
}

void draw_line_to_frame(int x, int wall_height)
{
	int	wall_start;
	int	wall_end;
	int	y;

	wall_start = HEIGHT/2 - wall_height/2;
	if (wall_start < 0)
		wall_start = 0;
	wall_end = HEIGHT/2 + wall_height/2;
	if(wall_end > HEIGHT - 1)
		wall_end = HEIGHT - 1;
	y = 0;
	while (y < HEIGHT)
	{
		if (y < wall_start)
			put_pixel_to_frame(x, y, game_object()->graphics.colors.ceiling);
		else if (y > wall_end)
			put_pixel_to_frame(x, y, game_object()->graphics.colors.floor);
		else
			put_pixel_to_frame(x, y, 0x55555);

		y++;
	}
}

void render_frame()
{
	t_vector	ray;
	t_game		*game;
	int 		x;

	game = game_object();
	x = 0;
	while (x < WIDTH)
    {
       	ray = get_ray_direction(x, game->player.camera, game->player.dir);
        double distance = do_dda(game->player.pos, ray);
        draw_line_to_frame((HEIGHT/distance), x);
	}
}

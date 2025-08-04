/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 11:34:53 by hsamir            #+#    #+#             */
/*   Updated: 2025/08/04 20:56:32 by hsamir           ###   ########.fr       */
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

	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return ;

	f = &game_obj()->graphics.frame;
	byte_per_pixel = f->bits_per_pixel / 8;
	addr = f->data_addr + f->size_line * y + byte_per_pixel * x;
	ft_memcpy(addr, &pixel, byte_per_pixel);
}

int get_pixel_from_image(t_image *img, int x, int y)
{
	int		byte_per_pixel;
	char	*addr;
	int		pixel;

	if (x < 0 || x >= img->width || y < 0 || y >= img->height)
		return (0);
	byte_per_pixel = img->bits_per_pixel / 8;
	addr = img->data_addr + img->size_line * y + byte_per_pixel * x;
	ft_memcpy(&pixel, addr, byte_per_pixel);
	return (pixel);
}

t_image	*get_wall_texture(int side, t_vector ray)
{
	if (side == SIDE_X)
	{
		if (ray.x < 0)
			return (&game_obj()->graphics.textures.west);
		else
			return (&game_obj()->graphics.textures.east);
	}
	else
	{
		if (ray.y < 0)
			return (&game_obj()->graphics.textures.north);
		else
			return (&game_obj()->graphics.textures.south);
	}
}

void draw_line_to_frame(t_column *c)
{
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		if (y < c->wall_start)
			put_pixel_to_frame(c->x, y, game_obj()->graphics.colors.ceiling);
		else if (y > c->wall_end)
			put_pixel_to_frame(c->x, y, game_obj()->graphics.colors.floor);
		else
		{
			put_pixel_to_frame(c->x, y, get_pixel_from_image(c->texture, c->pixel.x, c->pixel.y));
			c->pixel.y += c->step_y;
		}
		y++;
	}
}



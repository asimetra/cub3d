/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdaban <sdaban@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 02:59:46 by hsamir            #+#    #+#             */
/*   Updated: 2025/08/02 15:10:05 by sdaban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHICS_H
# define GRAPHICS_H

# include "event.h"
# include "element.h"

typedef struct s_mlx
{
	void	*mlx;
	void	*mlx_win;
	t_event	events;
}	t_mlx;

typedef struct s_image
{
	void	*ptr;
	char	*data_addr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	int		width;
	int		height;
}	t_image;

typedef struct s_texture
{
	t_image	north;
	t_image	east;
	t_image	south;
	t_image	west;
}	t_texture;

typedef struct s_color
{
	int		floor;
	int		ceiling;
}	t_color;

typedef struct s_graphics
{
	t_mlx			mlx;
	t_texture		textures;
	t_color			colors;
	t_image			frame;
	unsigned long	frame_time;
}					t_graphics;

void	fini_graphics(void);
void	init_graphics(t_element *e);
void	render(void);
#endif

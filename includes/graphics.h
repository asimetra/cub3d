/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 02:59:46 by hsamir            #+#    #+#             */
/*   Updated: 2025/08/04 13:49:39 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHICS_H
# define GRAPHICS_H

# include "event.h"
# include "element.h"
#include "types.h"
#include "cub3d.h"

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

typedef struct t_ray
{
	t_vector	dir;
	t_vector	delta;
	t_point		step;
	t_vector	side_dist;
	t_point		map;
	int			hit_side;
	double		perp_dist;
}	t_ray;


typedef struct s_column
{
	int			x;
	t_ray		ray;
	double		wall_height;
	int			wall_start;
	int			wall_end;
	t_image		*texture;
	t_vector	tex;
	double		step_y;
}	t_column;

void	fini_graphics(void);
void	init_graphics(t_element *e);
void	render(void);

t_vector	calc_delta_of(t_vector ray);
t_point		calc_step_of(t_vector ray);
t_vector	calc_side_dist(t_vector delta, t_vector player, t_point step);
double		calc_perp_dist(int hit_side, t_vector side_dist, t_vector delta);
t_vector	calc_ray_dir(int x, t_vector camera, t_vector dir);
t_ray		cast_ray(int x);



void			init_column_info(t_column *c, int x);
void			draw_line_to_frame(t_column *c);
t_image			*get_wall_texture(int side, t_vector ray);
#endif

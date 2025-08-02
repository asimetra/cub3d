/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 10:40:41 by hsamir            #+#    #+#             */
/*   Updated: 2025/08/02 10:50:43 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

#include "element.h"
#include "event.h"
#include "types.h"
#include "graphics.h"

#define PI 3.14159265358979323846

typedef struct s_map_line {
	char	*line;
	int		len;
}		t_map_line;

typedef struct s_map {
	t_map_line	*lines;
	int			len;
}		t_map;

typedef struct s_player {
	t_vector	dir;
	t_vector	pos;
	t_vector	camera;
}		t_player;

typedef struct s_game {
	t_graphics	graphics;
	t_map		map;
	t_player	player;
}		t_game;

typedef struct t_ray
{
	t_vector	dir;
	int			hit_side;
	double		perp_dist;
	t_vector	origin;
}	t_ray;

typedef struct s_column_info
{
	int			x;
	double		wall_height;
	int			wall_start;
	int			wall_end;
	t_ray		ray;
	t_image		*texture;
	t_vector	tex;
	double		step_y;
}	t_column_info;

void	safe_exit(char *message, char *line, int line_number);

t_game	*game_object();

int				game_loop(void *param);

int				render_windows(void* pr);
void 			render_frame();
void			init_player(t_element *e);
void			init_map(t_element *e);

t_vector		get_ray_direction(int x, t_vector camera, t_vector dir);
void			do_dda(t_ray *ray);
void			init_column_info(t_column_info *c, int x);
t_image			*get_wall_texture(int side, t_vector ray);
void 			draw_line_to_frame(t_column_info *c);

#endif

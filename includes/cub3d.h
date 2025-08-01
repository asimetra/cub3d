/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 10:40:41 by hsamir            #+#    #+#             */
/*   Updated: 2025/08/01 19:14:09 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

#include "element.h"
#include "event.h"

#define PI 3.14159265358979323846

typedef struct s_mlx {
	void	*mlx;
	void	*mlx_win;
	t_event	events;
}	t_mlx;

typedef struct s_image {
	void	*ptr;
	char	*data_addr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
}	t_image;

typedef struct s_texture {
	t_image	north;
	t_image	east;
	t_image	south;
	t_image	west;
}	t_texture;

typedef struct s_color {
	int 		floor;
	int 		ceiling;
}				t_color;

typedef struct s_graphics {
	t_mlx			mlx;
	t_texture		textures;
	t_color			colors;
	t_image			frame;
	unsigned long	frame_time;
}					t_graphics;

typedef struct s_map_line {
	char	*line;
	int		len;
}		t_map_line;

typedef struct s_map {
	t_map_line	*lines;
	int			len;
}		t_map;

typedef struct s_vector {
	float	x;
	float	y;
}		t_vector;

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

void	safe_exit(char *message, char *line, int line_number);

t_game	*game_object();
void	fini_graphics();
void	init_graphics(t_element *e);

unsigned long	current_time_ms(void);
int				game_loop(void *param);

int				render_windows(void* pr);
void			init_player(t_element *e);
void			init_map(t_element *e);

t_vector		get_ray_direction(int x, t_vector camera, t_vector dir);
double				do_dda(t_vector p, t_vector ray);

#endif

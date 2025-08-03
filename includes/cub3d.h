/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdaban <sdaban@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 10:40:41 by hsamir            #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2025/07/24 14:34:53 by hsamir           ###   ########.fr       */
=======
/*   Updated: 2025/08/02 15:06:32 by sdaban           ###   ########.fr       */
>>>>>>> 0acf8bb
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "element.h"
# include "event.h"
# include "types.h"
# include "graphics.h"

<<<<<<< HEAD
#include "element.h"

typedef enum e_direction
=======
# define PI 3.14159265358979323846

typedef struct s_map_line
>>>>>>> 0acf8bb
{
	char	*line;
	int		len;
}		t_map_line;

typedef struct s_map
{
	t_map_line	*lines;
	int			len;
}		t_map;

typedef struct s_player
{
	t_vector	dir;
	t_vector	pos;
	t_vector	camera;
}		t_player;

<<<<<<< HEAD
typedef struct s_color {
	int 		floor;
	int 		ceiling;
}				t_color;

typedef struct s_graphics {
	t_mlx	mlx;
	t_texture textures;
	t_color		colors;
}		t_graphics;

typedef	char** t_map;

typedef struct s_position {
	float	x;
	float	y;
}		t_position;

typedef struct s_player {
	float		angle;
	t_position	player_pos;
}		t_player;

typedef struct s_game {
	t_graphics	graphics;
	t_map		map;
	t_player	player;
}		t_game;

void	safe_exit(char *message, char *line, int line_number);
=======
typedef struct s_game
{
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

void			safe_exit(char *message, char *line, int line_number);

t_game			*game_object(void);

int				game_loop(void *param);

int				render_windows(void *pr);
void			render_frame(void);
void			init_player(t_element *e);
void			init_map(t_element *e);

t_vector		get_ray_direction(int x, t_vector camera, t_vector dir);
void			do_dda(t_ray *ray);
void			init_column_info(t_column_info *c, int x);
t_image			*get_wall_texture(int side, t_vector ray);
void			draw_line_to_frame(t_column_info *c);
>>>>>>> 0acf8bb

int		str_to_rgb(char	*input);

t_game	*game_object();

void	fini_graphics();
void	init_graphics(t_element *e);
#endif

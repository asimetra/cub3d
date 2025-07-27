/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 10:40:41 by hsamir            #+#    #+#             */
/*   Updated: 2025/07/27 12:04:07 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

/* ************************************************************************** */

#include "element.h"
#include "event.h"


typedef struct s_mlx {
	void	*mlx;
	void	*mlx_win;
	t_event	events;
}	t_mlx;

typedef struct s_texture {
	void	*north;
	void	*east;
	void	*south;
	void	*west;
}	t_texture;

typedef struct s_color {
	int 		floor;
	int 		ceiling;
}				t_color;

typedef struct s_graphics {
	t_mlx			mlx;
	t_texture		textures;
	t_color			colors;
	unsigned long	frame_time;
}					t_graphics;

typedef	char** t_map;

typedef struct s_vector {
	float	x;
	float	y;
}		t_vector;

typedef struct s_player {
	t_vector	dir;
	t_vector	pos;
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

#endif

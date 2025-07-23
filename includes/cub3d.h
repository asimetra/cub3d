/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 10:40:41 by hsamir            #+#    #+#             */
/*   Updated: 2025/07/23 18:24:09 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

/* ************************************************************************** */

typedef enum e_direction
{
	UP = 119,
	DOWN = 115,
	LEFT = 97,
	RIGHT = 100
}	t_direction;

typedef struct s_mlx {
	void	*mlx;
	void	*mlx_win;
}	t_mlx;

typedef struct s_texture {
	void	*north;
	void	*east;
	void	*south;
	void	*west;
}	t_texture;

typedef struct s_graphics {
	t_mlx	mlx;
	t_texture textures;
}		t_graphics;

typedef	struct s_map {
	char	**map;
	int		width;
	int		height;
}	t_map;

typedef struct s_position {
	float	x;
	float	y;
}		t_position;

typedef struct s_player {
	float		angle;
	t_position	player_pos;
}		t_player;

typedef struct s_color {
	int 		floor;
	int 		ceiling;
}				t_color;

typedef struct s_game {
	t_graphics	graphics;
	t_map		map;
	t_player	player;
	t_color		colors;
}		t_game;

void	safe_exit(char *message, char *line, int line_number);

int		str_to_rgb(char	*input);

#endif

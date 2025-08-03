/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 10:40:41 by hsamir            #+#    #+#             */
/*   Updated: 2025/08/03 18:40:00 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "element.h"
# include "event.h"
# include "types.h"
# include "graphics.h"

# define PI 3.14159265358979323846

typedef struct s_map_line
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

typedef struct s_game
{
	t_graphics	graphics;
	t_map		map;
	t_player	player;
}		t_game;

void			init_player(t_element *e);
void			init_map(t_element *e);

void			safe_exit(char *message, char *line, int line_number);

t_game			*game_object(void);

int				game_loop(void *param);
int				render_windows(void *pr);
void			render_frame(void);


#endif

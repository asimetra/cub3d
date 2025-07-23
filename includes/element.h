/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 18:30:44 by hsamir            #+#    #+#             */
/*   Updated: 2025/07/21 21:54:41 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ELEMENT_H
# define ELEMENT_H

#include <stddef.h>

# define MAP_CHR	"01NSEW "
# define PLAYER_CHR	"NSEW"
# define FLAG_TEXTURE (T_NORTH | T_SOUTH | T_WEST | T_EAST)
# define FLAG_COLOR (T_FLOOR | T_CEIL)
# define FLAG_ALL	(FLAG_TEXTURE | FLAG_COLOR | T_MAP)
# define FLAG_PLAYER (T_PLAYER_N | T_PLAYER_S | T_PLAYER_E | T_PLAYER_W)

typedef enum e_element_type
{
	T_EMPTY = 0,
	T_NORTH = 1 << 0,
	T_SOUTH = 1 << 1,
	T_WEST = 1 << 2,
	T_EAST = 1 << 3,
	T_FLOOR = 1 << 4,
	T_CEIL = 1 << 5,
	T_MAP = 1 << 6,
	T_INVALID = 1 << 7,
	T_PLAYER_N = 1 << 8,
	T_PLAYER_S = 1 << 9,
	T_PLAYER_E = 1 << 10,
	T_PLAYER_W = 1 << 8
}					t_element_type;

typedef union u_value
{
	char			*content;
	int				color;
}					t_value;

typedef struct s_element
{
	t_element_type	type;
	t_value			value;
	int				line;
	struct s_element	*next;
}					t_element;

typedef struct s_line
{
	char			*content;
	int				number;
}					t_line;

t_element			*create_element(t_element new_element);
t_element			*reverse_element_list(t_element *head);
t_element			*get_element(t_element *element, t_element_type type);

void				prepend_element(t_element **head, t_element *new_element);

int					is_texture(char *input);
int					is_color(char *input);
int					is_empty(char *input);
int					is_map_start(char *input);
int					is_map_chars(char *input);
int					is_empty(char *input);

t_element_type		get_texture_type(char *input);
t_element_type		get_color_type(char *input);
t_element_type		get_player_type(char *input);


typedef t_element_type		(*t_state)(t_element **head, t_line line, int s_mask);

t_element_type				texture_state(t_element **head, t_line line, int s_mask);
t_element_type				color_state(t_element **head, t_line line, int s_mask);
t_element_type				map_state(t_element **head, t_line line, int s_mask);
t_element_type				invalid_state(t_element **head, t_line line, int s_mask);

t_element					*parse_file(int fd);

#endif

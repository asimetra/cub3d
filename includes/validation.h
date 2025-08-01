/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 13:58:25 by sdaban            #+#    #+#             */
/*   Updated: 2025/08/01 10:52:06 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VALIDATION_H
#define VALIDATION_H

#include <stdbool.h>
#include "element.h"

typedef enum e_result_type
{
	OK = 0,
	ERROR = 1
}			t_result_type;

typedef struct s_result
{
	t_result_type		type;
	char				*err;

}			t_result;

#define USAGE_ERR "Usage: ./cub3D <name>.cub"
#define INVALID_EXT_ERR "Invalid file extension"
#define INVALID_FILE_ERR "Invalid <name>.cub file"
#define MISSING_ERR "missing elements in file"
#define INVALID_ELEMENT_ERR "invalid element identifier"

#define DUP_TEXTURE_ERR "duplicate texture"
#define EMPTY_TEXTURE_ERR "empty texture path"
#define INVALID_TEXTURE_ERR "invalid texture path"

#define DUP_COLOR_ERR "duplicate color"
#define INVALID_COLOR_ERR "invalid color value"

#define MAP_ERR "map is not last element"
#define DUP_PLAYER_ERR "duplicate player"
#define MAP_PLAYER_ERR "invalid player count on map line"
#define MISSING_PLAYER_ERR "missing player"
#define INVALID_MAP_ERR "invalid map"


int			is_valid_file_extension(char *file_path);
int			is_valid_player_count(char *input);
int			is_valid_map(t_element *element);
int			is_valid_position(int x, int y);


t_result	validate_color(t_element *element, int seen_mask);
t_result	validate_texture(t_element *element, int seen_mask);
t_result	validate_map(t_element *element, int seen_mask);
t_result 	validate_elements(t_element *elements, int s_mask);

#endif

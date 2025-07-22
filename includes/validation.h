/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 13:58:25 by sdaban            #+#    #+#             */
/*   Updated: 2025/07/22 19:00:37 by hsamir           ###   ########.fr       */
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

bool		v_color_value(int value);
bool		v_map();
bool		v_fc_colors(int floor, int ceiling); // floor and ceiling
bool		v_directions();

int			is_valid_file_extension(char *file_path);

t_result	validate_color(t_element element, int seen_mask);
t_result	validate_texture(t_element element, int seen_mask);
t_result	validate_map(t_element *elements, t_element element, int seen_mask);

#endif

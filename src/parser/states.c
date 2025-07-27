/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   states.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 15:50:39 by hsamir            #+#    #+#             */
/*   Updated: 2025/07/27 13:29:24 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "element.h"
#include "cub3d.h"
#include "libft.h"
#include "validation.h"
#include "string_utils.h"

/*
	I think my state machine is not good at dry principle.
	Maybe I should use factory pattern to create elements.
	Factory pattern: instead of create object directly, use a helper function to create it.
*/
t_element_type	texture_state(t_element **elements, t_line line, int s_mask)
{
	t_element	new_element;
	t_result	result;

	new_element = (t_element) {
			.type = get_texture_type(line.content),
			.value.content = ft_strtrim(line.content + 3, " \n"),
			.line = line.number
	};
	new_element.val_len = ft_strlen(new_element.value.content);
	result = validate_texture(&new_element, s_mask);
	if (result.type == ERROR)
		safe_exit(result.err, line.content, line.number);
	prepend_element(elements, create_element(new_element));
	return (new_element.type);
}

t_element_type	color_state(t_element **elements, t_line line, int s_mask)
{
	t_element	new_element;
	t_result	result;

	new_element = (t_element) {
		.type = get_color_type(line.content),
		.value.color = str_to_rgb(ft_strtrim(line.content + 2, " \n")),
		.line = line.number
	};
	result = validate_color(&new_element, s_mask);
	if (result.type == ERROR)
		safe_exit(result.err, line.content, line.number);
	prepend_element(elements, create_element(new_element));
	return (new_element.type);
}

t_element_type map_state(t_element **elements, t_line line, int s_mask)
{
	t_element	new_element;
	t_result	result;

	new_element	= (t_element) {
		.type = T_MAP | get_player_type(line.content),
		.value.content = ft_strtrim(line.content, "\n"),
		.line = line.number,
	};
	new_element.val_len = ft_strlen(new_element.value.content);
	result = validate_map(&new_element, s_mask);
	if (result.type == ERROR)
		safe_exit(result.err, line.content, line.number);
	prepend_element(elements, create_element(new_element));
	return (new_element.type);
}

t_element_type	invalid_state(t_element **elements, t_line line, int s_mask)
{
	(void) elements;
	(void) s_mask;
	safe_exit(INVALID_ELEMENT_ERR, line.content, line.number);
	return (T_INVALID);
}

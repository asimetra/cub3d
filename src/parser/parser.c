/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 14:52:02 by hsamir            #+#    #+#             */
/*   Updated: 2025/08/05 15:41:32 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "element.h"
#include <stdbool.h>
#include "memory_allocator/memory_allocator.h"
#include "cub3d.h"
#include "validation.h"
#include "get_next_line/get_next_line.h"

t_state	get_next_state(char *input)
{
	if (is_texture(input))
		return (texture_state);
	else if (is_color(input))
		return (color_state);
	else if (is_empty(input))
		return (NULL);
	else if (is_map_start(input) && is_map_chars(input))
		return (map_state);
	return (invalid_state);
}

t_element_type	parse_line(t_element **elements, t_line line, int s_mask)
{
	t_state	next_state;

	next_state = get_next_state(line.content);
	if (next_state != NULL)
		return (next_state(elements, line, s_mask));
	if (s_mask & T_MAP)
		safe_exit(INVALID_ELEMENT_ERR, line.content, line.number);
	return (T_EMPTY);
}

t_element	*parse_file(int fd)
{
	t_element	*elements;
	char		*line;
	int			ln;
	int			s_mask;
	t_result	result;

	elements = NULL;
	ln = 0;
	s_mask = 0;
	while (true)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		s_mask |= parse_line(&elements, (t_line){line, ++ln}, s_mask);
		safe_free_ptr(line);
	}
	result = validate_elements(elements, s_mask);
	if (result.type == ERROR)
		safe_exit(result.err, NULL, 0);
	return (reverse_element_list(elements));
}

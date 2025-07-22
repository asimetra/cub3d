/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 14:52:02 by hsamir            #+#    #+#             */
/*   Updated: 2025/07/22 22:27:32 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "element.h"
#include <stdbool.h>
#include "memory_allocator.h"
#include "cub3d.h"
#include "validation.h"
#include "get_next_line.h"

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

t_element	*parse_file(int fd)
{
	t_element	*elements;
	t_state		next_state;
	char		*line;
	int			line_number;
	int			seen_mask;

	elements = NULL;
	line_number = 0;
	seen_mask = 0;
	while (true)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break;
		line_number++;
		next_state = get_next_state(line);
		if (next_state != NULL)
			seen_mask |= next_state(&elements,(t_line){line, line_number}, seen_mask);
		safe_free_ptr(line, TEMPORARY);
	}
	if ((seen_mask & FLAG_ALL) != FLAG_ALL)
		safe_exit(MISSING_ERR, NULL, 0);
	return (reverse_element_list(elements));
}

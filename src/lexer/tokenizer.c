/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 16:03:55 by hsamir            #+#    #+#             */
/*   Updated: 2025/07/19 14:10:21 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "token.h"
#include <stddef.h>
#include <stdbool.h>
#include "memory_allocator.h"
#include "get_next_line.h"
#include "libft.h"

t_state	get_state(char *input, int seen_mask)
{
	if (is_texture(input))
		return (texture_state);
	else if (is_color(input))
		return (color_state);
	else if (is_empty(input) && !(seen_mask & T_MAP))
		return (NULL);
	else if (is_map_start(input))
		return (map_state);
	return (invalid_state);
}

t_token	*tokenize_file(int fd)
{
	t_token	*head_token;
	t_state	state;
	int		seen_mask;
	int		line_number;
	char	*line;

	head_token = NULL;
	seen_mask = 0;
	line_number = 0;
	while (true)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break;
		line_number++;
		state = get_state(line, seen_mask);
		if (state != NULL)
			seen_mask |= state(line, &head_token, seen_mask, line_number);
		safe_free_ptr(line, TEMPORARY);
	}
	return (reverse_token_list(head_token));
}

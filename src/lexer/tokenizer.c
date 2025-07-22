/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 16:03:55 by hsamir            #+#    #+#             */
/*   Updated: 2025/07/21 21:50:03 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "token.h"
#include <stddef.h>
#include <stdbool.h>
#include "memory_allocator.h"
#include "get_next_line.h"
#include "libft.h"

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

t_token_type	lex_line(t_token **head_token, char *input, int line)
{
	t_token	*token;
	t_state	next_state;

	next_state = get_next_state(input);
	if (next_state == NULL)
		return (T_EMPTY);
	token = next_state(input, line);
	prepend_token(head_token, token);
	return (token->type);
}

t_token	*tokenize_file(int fd)
{
	t_token	*head_token;
	t_token_type type;
	int		line_number;
	char	*line;

	head_token = NULL;
	line_number = 0;
	while (true)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break;
		type = lex_line(&head_token, line, ++line_number);
		if (type & T_INVALID)
			break;
		safe_free_ptr(line, TEMPORARY);
	}
	return (reverse_token_list(head_token));
}

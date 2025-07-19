/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 16:03:55 by hsamir            #+#    #+#             */
/*   Updated: 2025/07/19 10:16:48 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "token.h"
#include <stddef.h>
#include <stdbool.h>
#include "memory_allocator.h"
#include "get_next_line.h"
#include "libft.h"

int	texture_state(char *input, t_token **head_token, int seen_mask)
{
	t_token	new_token;

	new_token.type = get_texture_type(input);
	if (seen_mask & new_token.type)
		safe_exit("Duplicate texture type found");
	new_token.content = ft_strtrim(input + 3, " \n"); //NE ./test
	prepend_token(head_token, create_token(new_token));
	return (new_token.type);
}

int	color_state(char *input, t_token **head_token, int seen_mask)
{
	t_token	new_token;

	new_token.type = get_color_type(input);
	if (seen_mask & new_token.type)
		safe_exit("Duplicate color type found");
	new_token.content = ft_strtrim(input + 2, " \n");
	prepend_token(head_token, create_token(new_token));
	return (new_token.type);
}

int	map_state(char *input, t_token **head_token, int seen_mask)
{
	t_token	new_token;
	if ((seen_mask | T_MAP) != FLAG_ALL)
		safe_exit("Map must be last token");
	if (!is_map_chars(input))
		safe_exit("Invalid map start or characters");
	new_token.type = T_MAP;
	new_token.content = ft_strtrim(input,"\n");
	prepend_token(head_token, create_token(new_token));
	return (new_token.type);
}

int	invalid_state(char *input, t_token **head_token, int seen_mask)
{
	(void)input;
	(void)head_token;
	(void)seen_mask;
	safe_exit("Invalid token found");
	return (T_INVALID);
}

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
	char	*line;

	head_token = NULL;
	seen_mask = 0;
	while (true)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break;
		state = get_state(line, seen_mask);
		if (state != NULL)
			seen_mask |= state(line, &head_token, seen_mask);
		safe_free_ptr(line, TEMPORARY);
	}
	return (reverse_token_list(head_token));
}

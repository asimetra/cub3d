/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 16:03:55 by hsamir            #+#    #+#             */
/*   Updated: 2025/07/18 19:07:07 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "token.h"
#include <stddef.h>

void	texture_state(char *input, t_token **head_token);

void	map_state(char *input, t_token **head_token);

void	color_state(char *input, t_token **head_token);

void	invalid_state(char *input, t_token **head_token);

t_state	get_parser_state(char *input)
{
	if (is_texture(input))
		return (texture_state);
	else if (is_map(input))
		return (map_state);
	else if (is_color(input))
		return (color_state);
	else if (is_empty(input))
		return (NULL);
	return (invalid_state);
}

t_token	*parse_file(int fd)
{
	t_token	*head_token;
	char	*line;
	t_state	state;

	head_token = NULL;
	while (get_next_line(fd, &line) > 0)
	{
		state = get_parser_State(line);
		if (state != NULL)
			state(line, &head_token);
	}
	return (head_token);
}

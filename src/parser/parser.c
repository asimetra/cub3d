/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 16:03:55 by hsamir            #+#    #+#             */
/*   Updated: 2025/07/18 23:30:30 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "token.h"
#include <stddef.h>
#include <stdbool.h>
#include "get_next_line.h"
#include "libft.h"

void	texture_state(char *input, t_token **head_token, int *seen_mask)
{
	t_token	new_token;

	new_token.type = get_texture_type(input);
	if (*seen_mask & new_token.type)
		safe_exit("Duplicate texture type found");
	new_token.content = ft_strtrim(input, " \n");
	prepend_token(
		head_token,
		create_token(new_token)
	);
	*seen_mask |= new_token.type;
}

void	color_state(char *input, t_token **head_token, int *seen_mask)
{
	t_token	new_token;

	new_token.type = get_color_type(input);
	if (*seen_mask & new_token.type)
		safe_exit("Duplicate color type found");
	new_token.content = ft_strtrim(input, " \n");
	prepend_token(
		head_token,
		create_token(new_token)
	);
	*seen_mask |= new_token.type;
}

void	map_state(char *input, t_token **head_token, int *seen_mask)
{
	t_token	new_token;

	new_token.type = T_MAP;
	if (*seen_mask != (FLAG_TEXTURE | FLAG_COLOR))
		safe_exit("Map must be last token");
}

t_state	get_parser_state(char *input)
{
	if (is_texture(input))
		return (texture_state);
	else if (is_empty(input))
		return (NULL);
	else if (is_color(input))
		return (color_state);
	return (map_state);
}

t_token	*parse_file(int fd)
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
		state = get_parser_state(line);
		if (state != NULL)
			state(line, &head_token, &seen_mask);
	}
	return (head_token);
}

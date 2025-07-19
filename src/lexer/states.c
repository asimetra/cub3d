/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   states.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 14:10:09 by hsamir            #+#    #+#             */
/*   Updated: 2025/07/19 14:17:48 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"
#include "cub3d.h"

int	invalid_state(char *input, void *error, int flag, int line)
{
	if (flag & T_INVALID)
		safe_exit(error, input, line);
	else
		safe_exit("Invalid token found", input, line);
	return (T_INVALID);
}

int	texture_state(char *input, void *head_token, int s_mask, int line)
{
	t_token	new_token;

	new_token.type = get_texture_type(input);
	if (s_mask & new_token.type)
		invalid_state(input, "Duplicate texture type found", T_INVALID, line);
	new_token.line = line;
	new_token.content = ft_strtrim(input + 3, " \n"); //NO ./test
	prepend_token(head_token, create_token(new_token));
	return (new_token.type);
}

int	color_state(char *input, void *head_token, int s_mask, int line)
{
	t_token	new_token;

	new_token.type = get_color_type(input);
	if (s_mask & new_token.type)
		invalid_state(input, "Duplicate color type found", T_INVALID, line);
	new_token.line = line;
	new_token.content = ft_strtrim(input + 2, " \n");
	prepend_token(head_token, create_token(new_token));
	return (new_token.type);
}

int	map_state(char *input, void *head_token, int seen_mask, int line)
{
	t_token	new_token;

	if ((seen_mask | T_MAP) != FLAG_ALL)
		invalid_state(input, "Map must be last token", T_INVALID, line);
	if (!is_map_chars(input))
		invalid_state(input, "Invalid map start or characters", T_INVALID, line);
	new_token.line = line;
	new_token.type = T_MAP;
	new_token.content = ft_strtrim(input,"\n");
	prepend_token(head_token, create_token(new_token));
	return (new_token.type);
}

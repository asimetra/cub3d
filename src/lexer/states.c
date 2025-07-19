/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   states.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 14:10:09 by hsamir            #+#    #+#             */
/*   Updated: 2025/07/19 14:29:19 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"
#include "cub3d.h"
#include "libft.h"

int	invalid_state(char *input, void *error, int flag, int line)
{
	if (flag & T_INVALID)
		safe_exit(error, input, line);
	else
		safe_exit(INVALID_ERR, input, line);
	return (T_INVALID);
}

int	texture_state(char *input, void *head_token, int s_mask, int line)
{
	t_token	new_token;

	new_token.type = get_texture_type(input);
	if (s_mask & new_token.type)
		invalid_state(input, DUPTEXTURE_ERR, T_INVALID, line);
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
		invalid_state(input, DUPCOLOR_ERR, T_INVALID, line);
	new_token.line = line;
	new_token.content = ft_strtrim(input + 2, " \n");
	prepend_token(head_token, create_token(new_token));
	return (new_token.type);
}

int	map_state(char *input, void *head_token, int seen_mask, int line)
{
	t_token	new_token;

	if ((seen_mask | T_MAP) != FLAG_ALL)
		invalid_state(input, MAP_ERR, T_INVALID, line);
	if (!is_map_chars(input))
		invalid_state(input, MAPCHARS_ERR, T_INVALID, line);
	new_token.line = line;
	new_token.type = T_MAP;
	new_token.content = ft_strtrim(input,"\n");
	prepend_token(head_token, create_token(new_token));
	return (new_token.type);
}

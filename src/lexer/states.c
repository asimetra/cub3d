/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   states.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 14:10:09 by hsamir            #+#    #+#             */
/*   Updated: 2025/07/22 08:34:46 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"
#include "cub3d.h"
#include "libft.h"

t_token	*invalid_state(char *input, int line)
{
	return (create_token((t_token){
			.type = T_INVALID,
			.content = ft_strtrim(input,"\n"),
			.line = line
		}
	));
}

t_token	*texture_state(char *input, int line)
{
	return (create_token((t_token){
			.type = get_texture_type(input),
			.content = ft_strtrim(input + 3, " \n"),
			.line = line
		}
	));
}

t_token	*color_state(char *input, int line)
{
	return (create_token((t_token){
			.type = get_color_type(input),
			.content = ft_strtrim(input + 2, " \n"),
			.line = line
		}
	));
}

t_token	*map_state(char *input, int line)
{
	return (create_token((t_token){
			.type = T_MAP,
			.content = ft_strtrim(input,"\n"),
			.line = line
		}
	));
}

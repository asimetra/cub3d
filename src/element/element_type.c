/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element_type.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 23:13:15 by hsamir            #+#    #+#             */
/*   Updated: 2025/07/22 22:09:33 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "element.h"
#include "libft.h"

t_element_type	get_texture_type(char *input)
{
	if (ft_strncmp(input, "NO ", 3) == 0)
		return (T_NORTH);
	else if (ft_strncmp(input, "SO ", 3) == 0)
		return (T_SOUTH);
	else if (ft_strncmp(input, "WE ", 3) == 0)
		return (T_WEST);
	else if (ft_strncmp(input, "EA ", 3) == 0)
		return (T_EAST);
	return (T_INVALID);
}

t_element_type	get_color_type(char *input)
{
	if (ft_strncmp(input, "F ", 2) == 0)
		return (T_FLOOR);
	return (T_CEIL);
}

t_element_type	get_player_type(char *input)
{
	int				index;

	index = 0;
	while (input[index])
	{
		if (ft_strchr(PLAYER_CHR, input[index]))
			return (T_PLAYER);
		index++;
	}
	return (0);
}

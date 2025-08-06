/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   classify.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdaban <sdaban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 18:37:35 by hsamir            #+#    #+#             */
/*   Updated: 2025/08/06 11:41:11 by sdaban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "element.h"
#include "libft.h"
#include "string_utils.h"

int	is_texture(char *input)
{
	return (ft_strncmp(input, "NO ", 3) == 0 || ft_strncmp(input, "SO ", 3) == 0
		|| ft_strncmp(input, "WE ", 3) == 0 || ft_strncmp(input, "EA ",
			3) == 0);
}

int	is_color(char *input)
{
	return (ft_strncmp(input, "F ", 2) == 0 || ft_strncmp(input, "C ", 2) == 0);
}

int	is_empty(char *input)
{
	return (str_equal(input, "\n"));
}

/* Valid Map Characters:
	'0' for empty space,
	'1' for wall,
	'N','S','E','W' for player starting positions,
	' ' space are valid part and are up to you to handle
*/
int	is_map_chars(char *input)
{
	int	index;

	index = 0;
	while (input[index] && input[index] != '\n')
	{
		if (!includes(MAP_CHR, input[index]))
			return (0);
		index++;
	}
	return (1);
}

int	is_map_start(char *input)
{
	return (input[0] == '1' || input[0] == ' ');
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 14:07:22 by sdaban            #+#    #+#             */
/*   Updated: 2025/07/23 12:35:49 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "element.h"
#include "string_utils.h"
#include "limits.h"

int	is_valid_player_count(char *input)
{
	int index;
	int	p_count;

	index = 0;
	p_count = 0;
	while (input[index])
	{
		if (ft_strchr(PLAYER_CHR, input[index]))
			p_count++;
		index++;
	}
	return (p_count == 1 || p_count == 0);
}

int	is_valid_file_extension(char *file_path)
{
	return (ends_with(file_path, ".cub"));
}

int	is_in_uchar_range(int value)
{
	return (value >= 0 && value <= UCHAR_MAX);
}

int	is_valid_color_char(char c)
{
	return (ft_isdigit(c) || c == ',' || c == ' ');
}


// int is_valid_color_format(char *input)
// {
// 	int	index;
// 	int comma_count;

// 	index = 0;
// 	comma_count = 0;
// 	while (input[index])
// 	{
// 		if (is_valid_color_char(input[index]))
// 			return (0);
// 		if (input[index] == ',' || input[index] == ' ')
// 		{
// 			comma_count++;
// 			index = skip_comma(input, index);
// 		}
// 		index++;
// 		}
// }

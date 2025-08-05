/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convertion_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 17:19:10 by hsamir            #+#    #+#             */
/*   Updated: 2025/08/05 15:58:30 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "libft.h"
#include "memory_allocator/memory_allocator.h"
#include "string_utils.h"

int	is_all_digit(const char *input)
{
	int	index;

	index = -1;
	while (input[++index])
	{
		if (!ft_isdigit(input[index]))
			return (0);
	}
	return (1);
}

int	is_within_ubyte_range(long number)
{
	return (number >= 0 && number <= UCHAR_MAX);
}

int	str_to_ubyte(const char *str)
{
	long	total;
	int		i;

	if (*str == '\0' || !is_all_digit(str))
		return (-1);
	total = 0;
	i = 0;
	while (str[i])
	{
		total = total * 10 + str[i++] - '0';
		if (!is_within_ubyte_range(total))
			return (-1);
	}
	return (total);
}

int	str_to_rgb(char	*input)
{
	char	**rgb_str;
	char	*temp;
	int		index;
	int		rgb[3];

	index = 0;
	if (str_count(input, ',') != 2)
		return (-1);
	rgb_str = ft_split(input, ',');
	while (rgb_str[index] && index < 3)
	{
		temp = ft_strtrim(rgb_str[index], " ");
		rgb[index] = str_to_ubyte(temp);
		str_arr_free((char *[]){temp, rgb_str[index]}, 2);
		if (rgb[index] == -1)
			return (-1);  /*XXX we dont care about free cuz if is not valida we will call to safe_abort */
		index++;
	}
	if (index != 3)
		return (-1);
	safe_free_ptr(rgb_str);
	return (rgb[0] << 16 | rgb[1] << 8 | rgb[2]);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 13:03:45 by hsamir            #+#    #+#             */
/*   Updated: 2025/07/31 21:26:22 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "element.h"
#include "memory_allocator.h"

int is_valid_floor_block(t_element **m, size_t x, size_t y)
{
	return (x > 0 && m[y]->value.content[x - 1] != ' '
		&& x + 1 < m[y]->val_len  && m[y]->value.content[x + 1] != ' '
		&& y > 0 && x < m[y - 1]->val_len
		&& m[y - 1]->value.content[x] != ' '
		&& m[y + 1] != NULL && x < m[y + 1]->val_len
		&& m[y + 1]->value.content[x] != ' ');
}

int is_floor(char c)
{
	return (c == '0' || c == 'S' || c == 'N' || c == 'E' || c == 'W');
}


int	is_valid_map(t_element *element)
{
	t_element	**map_arr;
	char		*line;
	size_t		x;
	size_t		y;

	map_arr = element_map_to_arr(element);
	y = 0;
	while (map_arr[y])
	{
		x = 0;
		line = map_arr[y]->value.content;
		while (line[x])
		{
			if (is_floor(line[x]) && !is_valid_floor_block(map_arr, x, y))
			{
				safe_free_ptr(map_arr);
				return (0);
			}
			x++;
		}
		y++;
	}
	safe_free_ptr(map_arr);
	return (1);
}

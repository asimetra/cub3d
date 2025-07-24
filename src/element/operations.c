/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 12:25:33 by hsamir            #+#    #+#             */
/*   Updated: 2025/07/24 12:30:49 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "element.h"
#include "memory_allocator.h"

size_t	element_size(t_element *element)
{
	size_t len;

	len = 0;
	while (element != NULL)
	{
		len++;
		element = element->next;
	}
	return (len);
}

t_element	*reverse_element_list(t_element *element)
{
	t_element	*prev_element;
	t_element	*next_element;

	prev_element = NULL;
	while (element != NULL)
	{
		next_element = element->next;
		element->next = prev_element;
		prev_element = element;
		element = next_element;
	}
	return (prev_element);
}

t_element	**element_to_arr(t_element *element)
{
	t_element	**map_arr;
	t_element	*map;
	size_t 		len;
	size_t		index;

	index = 0;
	map = get_element(element, T_MAP);
	len = element_size(map);
	map_arr = safe_talloc(sizeof(t_element*) * (len + 1));
	while (index < len)
	{
		map_arr[index] = element;
		map = map->next;
		index++;
	}
	map_arr[index] = NULL;
	return (map_arr);
}

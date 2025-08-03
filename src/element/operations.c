/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: hsamir <hsamir@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 12:25:33 by hsamir            #+#    #+#             */
/*   Updated: 2025/07/24 14:44:42 by hsamir           ###   ########.fr       */
=======
/*   By: sdaban <sdaban@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 12:25:33 by hsamir            #+#    #+#             */
/*   Updated: 2025/08/02 15:20:20 by sdaban           ###   ########.fr       */
>>>>>>> 0acf8bb
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "element.h"
<<<<<<< HEAD
#include "memory_allocator.h"

size_t	element_count(t_element *element, t_element_type type)
{
	size_t len;
=======
#include "memory_allocator/memory_allocator.h"
#include "cub3d.h"

size_t	element_count(t_element *element, t_element_type type)
{
	size_t	len;
>>>>>>> 0acf8bb

	len = 0;
	while (element != NULL)
	{
		if (element->type & type)
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

t_element	**element_map_to_arr(t_element *e)
{
	t_element	**arr;
<<<<<<< HEAD
	size_t 		len;
=======
	size_t		len;
>>>>>>> 0acf8bb
	size_t		index;

	index = 0;
	len = element_count(get_element(e, T_MAP), T_MAP);
<<<<<<< HEAD
	arr = safe_talloc(sizeof(t_element*) * (len + 1));
=======
	arr = safe_malloc(sizeof(t_element *) * (len + 1));
>>>>>>> 0acf8bb
	while (index < len)
	{
		arr[index] = e;
		e = e->next;
		index++;
	}
	arr[index] = NULL;
	return (arr);
}
<<<<<<< HEAD

char	**element_map_to_str_arr(t_element *e)
{
	char		**arr;
	size_t 		len;
	size_t		index;

	index = 0;
	len = element_count(get_element(e, T_MAP), T_MAP);
	arr = safe_talloc(sizeof(char*) * (len + 1));
	while (index < len)
	{
		arr[index] = e->value.content;
		e = e->next;
		index++;
	}
	arr[index] = NULL;
	return (arr);
}
=======
>>>>>>> 0acf8bb

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 12:25:33 by hsamir            #+#    #+#             */
/*   Updated: 2025/07/24 14:25:47 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "element.h"
#include "memory_allocator.h"

size_t	element_count(t_element *element, t_element_type type)
{
	size_t len;

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

t_element	**element_to_arr(t_element *e, t_element_type type)
{
	t_element	**arr;
	size_t 		len;
	size_t		index;

	index = 0;
	len = element_count(e, type);
	arr = safe_talloc(sizeof(t_element*) * (len + 1));
	while (index < len)
	{
		arr[index] = e;
		e = e->next;
		index++;
	}
	arr[index] = NULL;
	return (arr);
}

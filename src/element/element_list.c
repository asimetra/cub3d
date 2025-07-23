/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 18:29:48 by hsamir            #+#    #+#             */
/*   Updated: 2025/07/23 21:13:33 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory_allocator.h"
#include "element.h"

t_element	*create_element(t_element new_element)
{
	t_element	*element;

	element = safe_talloc(sizeof(t_element));
	if (element == NULL)
		return (NULL);
	*element = new_element;
	element->next = NULL;
	return (element);
}

t_element	*get_last_element(t_element *element)
{
	while (element->next)
		element = element->next;
	return (element);
}

void	prepend_element(t_element **head_element, t_element *new_element)
{
	if (*head_element == NULL)
		*head_element = new_element;
	else
	{
		new_element->next = *head_element;
		*head_element = new_element;
	}
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

t_element	*get_element(t_element *element, t_element_type type)
{
	while (element != NULL)
	{
		if (element->type & type)
			return (element);
		element = element->next;
	}
	return (NULL);
}

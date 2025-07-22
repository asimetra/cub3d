/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_elements.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 15:54:04 by hsamir            #+#    #+#             */
/*   Updated: 2025/07/22 19:47:02 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "element.h"
#include "validation.h"
#include "libft.h"
#include "string_utils.h"

t_result	validate_texture(t_element element, int seen_mask)
{
	int len;

	if (seen_mask & element.type)
		return ((t_result) {.type = ERROR, .err = "duplicate texture"});
	len = ft_strlen(element.content);
	if (len == 0)
		return ((t_result) {.type = ERROR, .err = "empty texture path"});
	if (!ends_with(element.content, ".xpm"))
		return ((t_result) {.type = ERROR, .err = "invalid texture path"});
	return ((t_result) {.type = OK, .err = NULL});
}

t_result	validate_color(t_element element, int seen_mask)
{
	if (seen_mask & element.type)
		return ((t_result) {.type = ERROR, .err = "duplicate texture"});
	return ((t_result) {.type = OK, .err = NULL});
}

t_result	validate_map(t_element *elements, t_element element, int seen_mask)
{
	(void)element;
	(void)elements;
	(void)seen_mask;
	return ((t_result) {.type = OK, .err = NULL});
}



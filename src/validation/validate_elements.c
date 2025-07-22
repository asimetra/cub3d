/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_elements.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 15:54:04 by hsamir            #+#    #+#             */
/*   Updated: 2025/07/22 19:21:18 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "element.h"
#include "validation.h"

t_result	validate_texture(t_element element, int seen_mask)
{
	(void)element;
	(void)seen_mask;
	return ((t_result) {.type = OK, .err = NULL});
}

t_result	validate_color(t_element element, int seen_mask)
{
	(void)element;
	(void)seen_mask;
	return ((t_result) {.type = OK, .err = NULL});
}

t_result	validate_map(t_element *elements, t_element element, int seen_mask)
{
	(void)element;
	(void)elements;
	(void)seen_mask;
	return ((t_result) {.type = OK, .err = NULL});
}



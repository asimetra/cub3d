/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_elements.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 15:54:04 by hsamir            #+#    #+#             */
/*   Updated: 2025/07/23 21:18:00 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "element.h"
#include "validation.h"
#include "libft.h"
#include "string_utils.h"

t_result	validate_texture(t_element *element, int seen_mask)
{
	int len;

	if (seen_mask & element->type)
		return ((t_result) {.type = ERROR, .err = DUP_TEXTURE_ERR});
	len = ft_strlen(element->value.content);
	if (len == 0)
		return ((t_result) {.type = ERROR, .err = EMPTY_TEXTURE_ERR});
	if (!ends_with(element->value.content, ".xpm"))
		return ((t_result) {.type = ERROR, .err = INVALID_TEXTURE_ERR});
	return ((t_result) {.type = OK, .err = NULL});
}

t_result	validate_color(t_element *element, int seen_mask)
{
	if (seen_mask & element->type)
		return ((t_result) {.type = ERROR, .err = DUP_COLOR_ERR});
	if (element->value.color == -1)
		return ((t_result) {.type = ERROR, .err = INVALID_COLOR_ERR});
	return ((t_result) {.type = OK, .err = NULL});
}

t_result	validate_map(t_element *element, int seen_mask)
{
	if (((seen_mask & FLAG_ALL) | T_MAP) != FLAG_ALL)
		return ((t_result) {.type = ERROR, .err = MAP_ERR});
	if (!is_valid_player_count(element->value.content))
		return ((t_result) {.type = ERROR, .err = MAP_PLAYER_ERR});
	if (seen_mask & FLAG_PLAYER &&  element->type & FLAG_PLAYER)
		return ((t_result) {.type = ERROR, .err = DUP_PLAYER_ERR});
	return ((t_result) {.type = OK, .err = NULL});
}



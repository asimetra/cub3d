/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdaban <sdaban@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 14:00:05 by sdaban            #+#    #+#             */
/*   Updated: 2025/07/20 20:29:37 by sdaban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "../includes/validation.h"
#include "../libs/libft/libft.h"
#include "../includes/string_utils.h"

bool	is_in_range(int value)
{
	return (value >= 0 && value <= 255);
}

bool	v_fc_colors(int floor, int ceiling)
{
	return (floor == ceiling);
}

bool	v_directions(void)
{
	return (false);
}

bool	v_map(void)
{
	return (false);
}

bool	v_color_value(char *str)
{
	trim_string(str); // -> 0,            255, 255              -> 0,255,255	
	return (false);
}

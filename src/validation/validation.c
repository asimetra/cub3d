/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdaban <sdaban@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 14:00:05 by sdaban            #+#    #+#             */
/*   Updated: 2025/07/19 14:14:53 by sdaban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "../includes/validation.h"

bool	is_in_range(int value)
{
	(void)value;
	return (value >= 0 && value <= 255);
}

bool	v_fc_colors(int floor, int ceiling)
{
	(void)floor;
	(void)ceiling;
	return (false);
}

bool	v_directions(void)
{
	return (false);
}

bool	v_map(void)
{
	return (false);
}

bool	v_color_value(int value)
{
	(void)value;
	return (false);
}

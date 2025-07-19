/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdaban <sdaban@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 13:58:25 by sdaban            #+#    #+#             */
/*   Updated: 2025/07/19 14:01:58 by sdaban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VALIDATION_H
#define VALIDATION_H

#include <stdbool.h>


bool		v_color_value(int value);
bool		v_map();
bool		v_fc_colors(int floor, int ceiling); // floor and ceiling
bool		v_directions();


#endif
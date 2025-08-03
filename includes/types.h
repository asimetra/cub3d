/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdaban <sdaban@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 01:03:07 by hsamir            #+#    #+#             */
/*   Updated: 2025/08/02 15:04:28 by sdaban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

# define SIDE_X 0
# define SIDE_Y 1

typedef struct s_vector
{
	float	x;
	float	y;
}		t_vector;

typedef struct s_point
{
	int		x;
	int		y;
}		t_point;

#endif

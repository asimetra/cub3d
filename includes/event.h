/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 12:02:09 by hsamir            #+#    #+#             */
/*   Updated: 2025/07/27 14:03:30 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENT_H
# define EVENT_H

typedef enum e_event_type
{
	E_UP = 119,
	E_DOWN = 115,
	E_LEFT = 97,
	E_RIGHT = 100,
	E_LEFT_ARROW = 65361,
	E_RIGHT_ARROW = 65363,
	E_ESC = 65307,
}	t_event_type;

typedef struct s_event {
	int		up;
	int		down;
	int		left;
	int		right;
	int		left_arrow;
	int		right_arrow;
	int		esc;
}	t_event;

int			key_press_hook(int keycode, t_event *event);
int			key_release_hook(int keycode, t_event *event);
void		key_event_handler(void);

void		init_mlx_event_hooks(void);

#endif

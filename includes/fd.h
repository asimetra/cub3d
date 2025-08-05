/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 14:35:23 by hsamir            #+#    #+#             */
/*   Updated: 2025/08/05 14:37:42 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FD_H
#define FD_H

int		*file_descripter();
int		open_fd(char *file);
void	close_fd(char _fd);

#endif

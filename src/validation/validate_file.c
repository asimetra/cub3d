/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 21:59:23 by hsamir            #+#    #+#             */
/*   Updated: 2025/07/21 22:27:39 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "string_utils.h"

int	is_valid_file_extension(char *file_path)
{
	int	i;

	i = ft_strlen(file_path);
	if (i >= 4 && str_equal(file_path + i - 4, ".cub"))
		return (1);
	return (0);
}

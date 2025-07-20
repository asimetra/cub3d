/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_operations.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdaban <sdaban@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 19:54:48 by hsamir            #+#    #+#             */
/*   Updated: 2025/07/20 20:28:28 by sdaban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	includes(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	str_equal(char *s1, char *s2)
{
	size_t	s1_len;

	if (!s1 || !s2)
		return (0);
	s1_len = ft_strlen(s1);
	if (s1_len != ft_strlen(s2))
		return (0);
	return (ft_strncmp(s1, s2, s1_len) == 0);
}

void	trim_string(char *str)
{
	int	r = 0, w = 0;

	while (str[r] && ft_isspace(str[r]))
		r++;
	while (str[r])
	{
		if (str[r] != ' ' && str[r] != '\t')
			str[w++] = str[r];
		else if (str[w - 1] != ',')
			str[w++] = ' ';
		r++;
		if (str[w - 1] == ',' && ft_isspace(str[r]))
			while (ft_isspace(str[r]))
				r++;
	}
	if (w > 0 && ft_isspace(str[w - 1]))
		w--;
	str[w] = 0;
}
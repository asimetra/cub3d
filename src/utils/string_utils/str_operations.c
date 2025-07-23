/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_operations.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 19:54:48 by hsamir            #+#    #+#             */
/*   Updated: 2025/07/23 13:50:59 by hsamir           ###   ########.fr       */
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

int	ends_with(char *str, char *suffix)
{
	size_t	suf_len;
	size_t	str_len;

	if (!str || !suffix)
		return (0);
	suf_len = ft_strlen(suffix);
	str_len = ft_strlen(str);
	if (str_len < suf_len)
		return (0);
	return (ft_strncmp(str + str_len - suf_len, suffix, str_len) == 0);

}

int	str_count(char *str, char c)
{
	int index;
	int count;

	index = 0;
	count = 0;
	while (str[index])
	{
		if (str[index] == c)
			count++;
		index++;
	}
	return (count);
}

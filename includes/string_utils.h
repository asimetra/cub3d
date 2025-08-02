/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdaban <sdaban@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 14:49:27 by hsamir            #+#    #+#             */
/*   Updated: 2025/08/02 15:10:15 by sdaban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRING_UTILS_H
# define STRING_UTILS_H

char	*str_arr_join(char	**strings, int count);
void	str_arr_free(char	**strings, int count);

int		includes(char *str, char c);
int		str_equal(char *s1, char *s2);
int		ends_with(char *str, char *suffix);
int		str_count(char *str, char c);
int		find_chars_index(char *str, char *chars);

int		str_to_rgb(char	*input);

#endif

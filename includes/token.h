/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 18:30:44 by hsamir            #+#    #+#             */
/*   Updated: 2025/07/19 11:53:09 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_H
# define TOKEN_H

# define MAP_CHR	"01NSEW "
# define FLAG_TEXTURE (T_NORTH | T_SOUTH | T_WEST | T_EAST)
# define FLAG_COLOR (T_FLOOR | T_CEIL)
# define FLAG_ALL	(FLAG_TEXTURE | FLAG_COLOR | T_MAP)

typedef enum e_token_type
{
	T_NORTH = 1 << 0,
	T_SOUTH = 1 << 1,
	T_WEST = 1 << 2,
	T_EAST = 1 << 3,
	T_FLOOR = 1 << 4,
	T_CEIL = 1 << 5,
	T_MAP = 1 << 6,
	T_INVALID = 1 << 7
}					t_token_type;

typedef struct s_token
{
	t_token_type	type;
	char			*content;
	struct s_token	*next;
}					t_token;

typedef int		(*t_state)(char *input, t_token **head_token, int seen_mask, int line_number);

t_token				*get_last_token(t_token *head_token);
t_token				*create_token(t_token new_token);
t_token				*reverse_token_list(t_token *token);

void				prepend_token(t_token **head_token, t_token *new_token);
void				remove_token(t_token **head, t_token *prev, t_token *token);
void				remove_token_by_flags(t_token **head_token, int flags);
void				insert_tokens(t_token **prev_token, t_token *tokens);

int					is_texture(char *input);
int					is_color(char *input);
int					is_empty(char *input);
int					is_map_start(char *input);
int					is_map_chars(char *input);
int					is_empty(char *input);

t_token_type		get_texture_type(char *input);
t_token_type		get_color_type(char *input);

t_token				*tokenize_file(int fd);

#endif

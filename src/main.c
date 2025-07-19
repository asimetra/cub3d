/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 00:21:31 by hsamir            #+#    #+#             */
/*   Updated: 2025/07/19 09:34:27 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory_allocator.h"
#include "cub3d.h"
#include "token.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

const char *token_type_str(t_token_type t)
{
	switch (t) {
		case T_NORTH: return "T_NORTH";
		case T_SOUTH: return "T_SOUTH";
		case T_EAST: return "T_EAST";
		case T_WEST: return "T_WEST";
		case T_FLOOR: return "T_FLOOR";
		case T_CEIL: return "T_CEIL";
		case T_MAP: return "T_MAP";
		default: return "UNKNOWN";
	}
}

void	debug_tokens(t_token *tokens)
{
	printf("\x1b[34m┌──────────────────────────────────────────────────── DEBUG TOKENS ─────────────────────────────────────────────────────┐\x1b[0m\n");
	while(tokens)
	{
        printf("│ \x1b[33m[%11s]\x1b[0m \x1b[32m\"%s\"\x1b[0m\n",
			token_type_str(tokens->type),
			tokens->content ? tokens->content : "(null)");
		tokens = tokens->next;
	}
	printf("\x1b[34m└───────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┘\x1b[0m\n");
}

void cub_main(void)
{

}


int	main(int argc, char **argv)
{
	t_token	*token;
	int		config_fd;

	(void)argv;
	token = NULL;
	if (argc != 2)
		safe_exit("Duplicate texture type found");
	config_fd = open(argv[1], O_RDONLY); //
	token = tokenize_file(config_fd);
	debug_tokens(token);
	cub_main();
	close(config_fd);
	return (0);
}


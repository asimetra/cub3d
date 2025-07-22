/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 00:21:31 by hsamir            #+#    #+#             */
/*   Updated: 2025/07/22 20:30:52 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory_allocator.h"
#include "cub3d.h"
#include "element.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include "validation.h"

const char *token_type_str(t_element_type t)
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

void	debug_tokens(t_element *tokens)
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
	t_element	*elements;
	int		map_fd;

	elements = NULL;
	if (argc != 2)
		safe_exit(USAGE_ERR, NULL, 0);
	if (!is_valid_file_extension(argv[1]))
		safe_exit(INVALID_EXT_ERR, NULL, 0);
	map_fd = open(argv[1], O_RDONLY);
	if (map_fd == -1)
		safe_exit(INVALID_FILE_ERR, NULL, 0);
	elements = parse_file(map_fd);
	if (elements == NULL)
		safe_exit(INVALID_FILE_ERR, NULL, 0);
	close(map_fd);
	debug_tokens(elements);
	cub_main();
	return (0);
}


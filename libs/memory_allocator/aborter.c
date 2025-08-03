/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aborter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 14:24:14 by hsamir            #+#    #+#             */
/*   Updated: 2025/08/02 18:27:45 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory_allocator.h"
#include <stdlib.h>

t_fini	*finalizer_func(void)
{
	static t_fini	fnl = NULL;

	return (&fnl);
}

void	safe_free(void)
{
	t_memory_block	**head;
	t_memory_block	*mem_block;
	t_memory_block	*next_mem_block;

	head = get_memory_head();
	mem_block = *head;
	while (mem_block)
	{
		next_mem_block = mem_block->next;
		free(mem_block->data);
		free(mem_block);
		mem_block = next_mem_block;
	}
	*head = NULL;
}

void	safe_free_ptr(void *ptr)
{
	t_memory_block	**head;
	t_memory_block	*mem_block;
	t_memory_block	*prev_mem_block;

	if (ptr == NULL)
		return ;
	head = get_memory_head();
	mem_block = *head;
	prev_mem_block = NULL;
	while (mem_block)
	{
		if (mem_block->data == ptr)
		{
			if (prev_mem_block == NULL)
				*head = mem_block->next;
			else
				prev_mem_block->next = mem_block->next;
			free(mem_block->data);
			free(mem_block);
			break ;
		}
		prev_mem_block = mem_block;
		mem_block = mem_block->next;
	}
}

void	register_finalizer_funct(t_fini finalizer)
{
	*finalizer_func() = finalizer;
}

int	safe_abort(int exit_code)
{
	t_fini	finalizer;

	finalizer = *finalizer_func();
	if (finalizer != NULL)
		finalizer();
	safe_free();
	exit(exit_code);
	return (exit_code);
}

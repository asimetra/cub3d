/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdaban <sdaban@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 14:24:09 by hsamir            #+#    #+#             */
/*   Updated: 2025/08/02 15:18:44 by sdaban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory_allocator.h"
#include <stdlib.h>

t_memory_block	**get_memory_head(void)
{
	static t_memory_block	*mem_block = {0};

	return (&mem_block);
}

void	safe_register_malloc(void *alloc_mem)
{
	t_memory_block	**head;
	t_memory_block	*mem_block;

	mem_block = malloc(sizeof(t_memory_block));
	if (!mem_block)
	{
		free(alloc_mem);
		safe_abort(STD_EXIT);
	}
	head = get_memory_head();
	*mem_block = (t_memory_block){
		.data = alloc_mem,
		.next = *head
	};
	*head = mem_block;
}

void	*safe_malloc(size_t size)
{
	void	*alloc_mem;

	alloc_mem = malloc(size);
	if (!alloc_mem)
		safe_abort(STD_EXIT);
	safe_register_malloc(alloc_mem);
	return (alloc_mem);
}

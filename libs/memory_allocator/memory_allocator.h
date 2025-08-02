/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_allocator.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdaban <sdaban@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 15:12:06 by hsamir            #+#    #+#             */
/*   Updated: 2025/08/02 15:18:37 by sdaban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEMORY_ALLOCATOR_H
# define MEMORY_ALLOCATOR_H

# include <stddef.h>

# define STD_EXIT 1

typedef struct s_memory_block
{
	void					*data;
	struct s_memory_block	*next;
}							t_memory_block;

typedef void				(*t_fini)(void);

t_memory_block				**get_memory_head(void);

void						*safe_malloc(size_t size);
void						safe_register_malloc(void *alloc_mem);

void						safe_free(void);
void						safe_free_ptr(void *ptr);
int							safe_abort(int exit_code);

void						register_finalizer_funct(t_fini finalizer);

#endif

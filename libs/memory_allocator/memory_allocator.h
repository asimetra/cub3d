/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_allocator.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD:includes/memory_allocator.h
/*   By: hsamir <hsamir@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 15:12:06 by hsamir            #+#    #+#             */
/*   Updated: 2025/07/24 11:56:05 by hsamir           ###   ########.fr       */
=======
/*   By: sdaban <sdaban@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 15:12:06 by hsamir            #+#    #+#             */
/*   Updated: 2025/08/02 15:18:37 by sdaban           ###   ########.fr       */
>>>>>>> 0acf8bb:libs/memory_allocator/memory_allocator.h
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

<<<<<<< HEAD:includes/memory_allocator.h
typedef void				(*t_fini)(void);

t_memory_block				**get_memory_head(t_mem_type mem_type);
=======
t_memory_block				**get_memory_head(void);
>>>>>>> 0acf8bb:libs/memory_allocator/memory_allocator.h

void						*safe_malloc(size_t size);
void						safe_register_malloc(void *alloc_mem);

void						safe_free(void);
void						safe_free_ptr(void *ptr);
int							safe_abort(int exit_code);

<<<<<<< HEAD:includes/memory_allocator.h
void						safe_free(t_mem_type mem_type);
void						safe_free_ptr(void *ptr, t_mem_type mem_type);
int							safe_abort(int exit_code);


=======
>>>>>>> 0acf8bb:libs/memory_allocator/memory_allocator.h
void						register_finalizer_funct(t_fini finalizer);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena_alloc.c */
/*                                                    +:+ +:+         +:+     */
/*   By: lmouta-g <lmouta-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 08:40:00 by lmouta-g          #+#    #+#             */
/*   Updated: 2026/05/15 08:40:00 by lmouta-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utility_library.h"
#include <stdint.h>

/**
 * align_arena_size - rounds size up to pointer alignment.
 */
static size_t	align_arena_size(size_t size)
{
	size_t	alignment;
	size_t	remainder;

	alignment = sizeof(void *);
	remainder = size % alignment;
	if (remainder == 0)
		return (size);
	if (size > SIZE_MAX - (alignment - remainder))
		return (0);
	return (size + alignment - remainder);
}

/**
 * arena_alloc - allocates aligned memory from the arena.
 */
void	*arena_alloc(t_arena *arena, size_t size)
{
	size_t	aligned_size;
	void	*allocation;

	if (!arena || size == 0)
		return (NULL);
	aligned_size = align_arena_size(size);
	if (aligned_size == 0 || arena->offset > arena->capacity
		|| aligned_size > arena->capacity - arena->offset)
		return (NULL);
	allocation = arena->buffer + arena->offset;
	arena->offset += aligned_size;
	return (allocation);
}

/**
 * arena_zalloc - allocates zeroed aligned memory from the arena.
 */
void	*arena_zalloc(t_arena *arena, size_t size)
{
	void	*allocation;

	allocation = arena_alloc(arena, size);
	if (!allocation)
		return (NULL);
	zero_memory(allocation, size);
	return (allocation);
}

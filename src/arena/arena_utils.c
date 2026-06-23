/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena_utils.c */
/*                                                    +:+ +:+         +:+     */
/*   By: lmouta-g <lmouta-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 08:40:00 by lmouta-g          #+#    #+#             */
/*   Updated: 2026/05/15 08:40:00 by lmouta-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * destroy_arena - frees an arena and its backing buffer.
 */
void	destroy_arena(t_arena *arena)
{
	if (!arena)
		return ;
	free(arena->buffer);
	free(arena);
}

/**
 * reset_arena - marks every arena allocation as reusable.
 */
void	reset_arena(t_arena *arena)
{
	if (!arena)
		return ;
	arena->offset = 0;
}

/**
 * arena_remaining - returns the number of bytes still available.
 */
size_t	arena_remaining(const t_arena *arena)
{
	if (!arena || arena->offset > arena->capacity)
		return (0);
	return (arena->capacity - arena->offset);
}

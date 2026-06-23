/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_arena.c */
/*                                                    +:+ +:+         +:+     */
/*   By: lmouta-g <lmouta-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 08:40:00 by lmouta-g          #+#    #+#             */
/*   Updated: 2026/05/15 08:40:00 by lmouta-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * create_arena - creates a fixed-size arena allocator.
 */
t_arena	*create_arena(size_t capacity)
{
	t_arena	*arena;

	if (capacity == 0)
		return (NULL);
	arena = malloc(sizeof(t_arena));
	if (!arena)
		return (NULL);
	arena->buffer = malloc(capacity);
	if (!arena->buffer)
	{
		free(arena);
		return (NULL);
	}
	arena->capacity = capacity;
	arena->offset = 0;
	return (arena);
}

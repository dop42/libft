/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocate_zeroed.c */
/*                                                    +:+ +:+         +:+     */
/*   By: lm0uta <lmouta-g@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 13:57:48 by lm0uta            #+#    #+#             */
/*   Updated: 2025/11/05 14:46:18 by lm0uta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"
#include <stdint.h>

void	*allocate_zeroed(size_t count, size_t size)
{
	void	*ptr;
	size_t	total;

	if (size != 0 && count > SIZE_MAX / size)
		return (NULL);
	total = count * size;
	ptr = malloc(total);
	if (ptr == NULL)
		return (NULL);
	zero_memory(ptr, total);
	return (ptr);
}

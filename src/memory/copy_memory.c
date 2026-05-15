/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_memory.c */
/*                                                    +:+ +:+         +:+     */
/*   By: lm0uta <lmouta-g@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 13:04:04 by lm0uta            #+#    #+#             */
/*   Updated: 2025/11/04 13:36:23 by lm0uta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utility_library.h"

void	*copy_memory(void *dst, const void *src, size_t len)
{
	size_t				i;
	unsigned char		*dest;
	const unsigned char	*source;

	if (!dst && !src)
		return (NULL);
	i = 0;
	dest = (unsigned char *)dst;
	source = (const unsigned char *)src;
	while (i < len)
	{
		dest[i] = source[i];
		i++;
	}
	return (dst);
}

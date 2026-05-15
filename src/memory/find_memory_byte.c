/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_memory_byte.c */
/*                                                    +:+ +:+         +:+     */
/*   By: lm0uta <lmouta-g@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 21:41:46 by lm0uta            #+#    #+#             */
/*   Updated: 2025/11/05 11:01:22 by lm0uta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utility_library.h"

void	*find_memory_byte(const void *s, int c, size_t n)
{
	const unsigned char	*ptr;
	unsigned char		ch;

	ptr = (const unsigned char *)s;
	ch = (unsigned char)c;
	while (n > 0)
	{
		if (*ptr == ch)
			return ((void *)ptr);
		ptr++;
		n--;
	}
	return (NULL);
}

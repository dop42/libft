/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   concat_string.c */
/*                                                    +:+ +:+         +:+     */
/*   By: lm0uta <lmouta-g@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 14:53:16 by lm0uta            #+#    #+#             */
/*   Updated: 2025/11/05 09:45:02 by lm0uta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utility_library.h"

size_t	concat_string(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;

	if (!dst && dstsize == 0)
		return (string_length(src));
	src_len = string_length(src);
	dst_len = 0;
	while (dst_len < dstsize && dst[dst_len] != '\0')
		dst_len++;
	if (dstsize <= dst_len)
		return (dstsize + src_len);
	i = 0;
	while (src[i] != '\0' && dst_len + i + 1 < dstsize)
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}

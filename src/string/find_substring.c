/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_substring.c */
/*                                                    +:+ +:+         +:+     */
/*   By: lm0uta <lmouta-g@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 11:03:16 by lm0uta            #+#    #+#             */
/*   Updated: 2025/11/05 12:06:06 by lm0uta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utility_library.h"

char	*find_substring(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	needle_len;

	needle_len = string_length(needle);
	if (needle_len == 0)
		return ((char *)haystack);
	i = 0;
	while (i < len && haystack[i])
	{
		if (i + needle_len > len)
			return (NULL);
		j = 0;
		while (j < needle_len && haystack[i + j] == needle[j])
			j++;
		if (j == needle_len)
			return ((char *)(haystack + i));
		i++;
	}
	return (NULL);
}

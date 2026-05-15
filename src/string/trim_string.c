/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim_string.c */
/*                                                    +:+ +:+         +:+     */
/*   By: lm0uta <lmouta-g@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 14:19:25 by lm0uta            #+#    #+#             */
/*   Updated: 2025/11/07 16:43:52 by lm0uta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utility_library.h"

static void	build_lookup(const char *set, bool lookup[256])
{
	size_t	i;

	i = 0;
	while (i < 256)
		lookup[i++] = false;
	while (*set)
		lookup[(unsigned char)*set++] = true;
}

char	*trim_string(char const *s1, char const *set)
{
	bool	lookup[256];
	size_t	start;
	size_t	end;
	char	*trimmed;

	if (!s1 || !set)
		return (NULL);
	build_lookup(set, lookup);
	start = 0;
	while (s1[start] && lookup[(unsigned char)s1[start]])
		start++;
	end = string_length(s1);
	while (end > start && lookup[(unsigned char)s1[end - 1]])
		end--;
	trimmed = (char *)malloc(end - start + 1);
	if (!trimmed)
		return (NULL);
	copy_memory(trimmed, s1 + start, end - start);
	trimmed[end - start] = '\0';
	return (trimmed);
}

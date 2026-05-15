/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_strings.c */
/*                                                    +:+ +:+         +:+     */
/*   By: lm0uta <lmouta-g@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 13:48:44 by lm0uta            #+#    #+#             */
/*   Updated: 2025/11/06 13:48:47 by lm0uta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utility_library.h"

char	*join_strings(char const *s1, char const *s2)
{
	size_t	len1;
	size_t	len2;
	char	*joined_str;

	if (!s1 || !s2)
		return (NULL);
	len1 = string_length(s1);
	len2 = string_length(s2);
	joined_str = (char *)malloc(len1 + len2 + 1);
	if (!joined_str)
		return (NULL);
	copy_memory(joined_str, s1, len1);
	copy_memory(joined_str + len1, s2, len2);
	joined_str[len1 + len2] = '\0';
	return (joined_str);
}

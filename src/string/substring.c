/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   substring.c */
/*                                                    +:+ +:+         +:+     */
/*   By: lm0uta <lmouta-g@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 14:59:16 by lm0uta            #+#    #+#             */
/*   Updated: 2025/11/06 13:48:31 by lm0uta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*substring(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	size_t	sub_len;
	char	*substr;

	if (!s)
		return (NULL);
	s_len = string_length(s);
	if (start >= s_len)
		return (duplicate_string(""));
	sub_len = len;
	if (s_len - start < sub_len)
		sub_len = s_len - start;
	substr = (char *)malloc(sub_len + 1);
	if (!substr)
		return (NULL);
	copy_memory(substr, s + start, sub_len);
	substr[sub_len] = '\0';
	return (substr);
}

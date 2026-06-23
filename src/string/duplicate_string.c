/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   duplicate_string.c */
/*                                                    +:+ +:+         +:+     */
/*   By: lm0uta <lmouta-g@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 14:32:26 by lm0uta            #+#    #+#             */
/*   Updated: 2025/11/06 13:48:38 by lm0uta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*duplicate_string(const char *s)
{
	size_t	len;
	char	*ptr;

	if (!s)
		return (NULL);
	len = string_length(s) + 1;
	ptr = malloc(len);
	if (ptr == NULL)
		return (NULL);
	copy_memory(ptr, s, len);
	return (ptr);
}

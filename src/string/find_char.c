/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_char.c */
/*                                                    +:+ +:+         +:+     */
/*   By: lm0uta <lmouta-g@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 14:55:32 by lm0uta            #+#    #+#             */
/*   Updated: 2025/11/05 09:45:02 by lm0uta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utility_library.h"

char	*find_char(const char *s, int c)
{
	unsigned char	target;

	target = (unsigned char)c;
	while (*s)
	{
		if ((unsigned char)*s == target)
			return ((char *)s);
		s++;
	}
	if (target == '\0')
		return ((char *)s);
	return (NULL);
}

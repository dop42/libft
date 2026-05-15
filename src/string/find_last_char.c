/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_last_char.c */
/*                                                    +:+ +:+         +:+     */
/*   By: lm0uta <lmouta-g@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 12:49:02 by lm0uta            #+#    #+#             */
/*   Updated: 2025/11/18 13:21:02 by lm0uta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utility_library.h"

char	*find_last_char(const char *str, int c)
{
	size_t	i;

	i = string_length(str) + 1;
	while (i--)
	{
		if (str[i] == (char)c)
			return ((char *)str + i);
	}
	return (NULL);
}

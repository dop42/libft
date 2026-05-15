/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_string.c */
/*                                                    +:+ +:+         +:+     */
/*   By: lm0uta <lmouta-g@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 15:38:52 by lm0uta            #+#    #+#             */
/*   Updated: 2025/11/14 15:38:57 by lm0uta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utility_library.h"

char	*map_string(char const *s, char (*f)(unsigned int, char))
{
	char	*dest;
	int		i;

	if (!s || !f)
		return (NULL);
	i = 0;
	dest = (char *)malloc(sizeof(char) * (string_length(s) + 1));
	if (dest == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		dest[i] = f(i, s[i]);
		++i;
	}
	dest[i] = '\0';
	return (dest);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c */
/*                                                    +:+ +:+         +:+     */
/*   By: lu-value <lu-value@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 00:00:00 by lu-value          #+#    #+#             */
/*   Updated: 2026/04/10 00:00:00 by lu-value         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int	print_string(char *str)
{
	size_t	len;

	if (!str)
		str = "(null)";
	len = string_length(str);
	write(1, str, len);
	return ((int)len);
}

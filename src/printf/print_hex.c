/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c */
/*                                                    +:+ +:+         +:+     */
/*   By: lu-value <lu-value@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 00:00:00 by lu-value          #+#    #+#             */
/*   Updated: 2026/04/10 00:00:00 by lu-value         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utility_library.h"

int	print_hex(char form, unsigned long long nbr)
{
	const char	*base;
	int			count;

	if (form == 'X')
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	count = 0;
	if (nbr >= 16)
		count += print_hex(form, nbr / 16);
	count += print_char(base[nbr % 16]);
	return (count);
}

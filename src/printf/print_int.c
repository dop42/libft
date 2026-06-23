/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c */
/*                                                    +:+ +:+         +:+     */
/*   By: lu-value <lu-value@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 00:00:00 by lu-value          #+#    #+#             */
/*   Updated: 2026/04/10 00:00:00 by lu-value         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int	print_int(int n)
{
	long	num;
	int		count;

	num = n;
	count = 0;
	if (num < 0)
	{
		count += print_char('-');
		num = -num;
	}
	if (num >= 10)
		count += print_int((int)(num / 10));
	count += print_char((char)((num % 10) + '0'));
	return (count);
}

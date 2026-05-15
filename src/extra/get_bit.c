/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_bit.c */
/*                                                    +:+ +:+         +:+     */
/*   By: lmouta-g <lmouta-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 12:07:36 by lmouta-g          #+#    #+#             */
/*   Updated: 2026/02/19 12:08:03 by lmouta-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utility_library.h"

int	get_bit(int num, int bit)
{
	unsigned int	value;

	if (bit < 0 || bit >= (int)(sizeof(unsigned int) * 8))
		return (0);
	value = (unsigned int)num;
	return ((value >> bit) & 1U);
}

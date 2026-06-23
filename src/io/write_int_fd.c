/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_int_fd.c */
/*                                                    +:+ +:+         +:+     */
/*   By: lm0uta <lmouta-g@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 13:29:41 by lm0uta            #+#    #+#             */
/*   Updated: 2025/11/12 13:29:44 by lm0uta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	write_int_fd(int n, int fd)
{
	char	buf[12];
	int		i;
	long	nb;

	if (fd < 0)
		return ;
	nb = n;
	i = 0;
	if (nb < 0)
	{
		write_char_fd('-', fd);
		nb = -nb;
	}
	if (nb == 0)
	{
		write_char_fd('0', fd);
		return ;
	}
	while (nb > 0)
	{
		buf[i++] = nb % 10 + '0';
		nb /= 10;
	}
	while (i--)
		write_char_fd(buf[i], fd);
}

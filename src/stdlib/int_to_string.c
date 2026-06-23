/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_to_string.c */
/*                                                    +:+ +:+         +:+     */
/*   By: lm0uta <lmouta-g@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 16:30:00 by lm0uta            #+#    #+#             */
/*   Updated: 2025/11/13 16:30:00 by lm0uta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static size_t	get_length(long n)
{
	size_t	len;

	len = (n <= 0);
	while (n != 0)
	{
		n /= 10;
		++len;
	}
	return (len);
}

static void	fill_digits(char *result, long nb, size_t len)
{
	if (nb == 0)
	{
		result[0] = '0';
		return ;
	}
	while (nb > 0)
	{
		result[--len] = (nb % 10) + '0';
		nb /= 10;
	}
}

char	*int_to_string(int n)
{
	char	*result;
	long	nb;
	size_t	len;

	nb = n;
	len = get_length(nb);
	result = (char *)malloc(len + 1);
	if (!result)
		return (NULL);
	result[len] = '\0';
	if (nb < 0)
	{
		result[0] = '-';
		nb *= -1;
	}
	fill_digits(result, nb, len);
	return (result);
}

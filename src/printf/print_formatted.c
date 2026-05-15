/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_formatted.c */
/*                                                    +:+ +:+         +:+     */
/*   By: lu-value <lu-value@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 00:00:00 by lu-value          #+#    #+#             */
/*   Updated: 2026/04/10 00:00:00 by lu-value         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utility_library.h"

static int	write_format(char format, va_list *args)
{
	if (format == 'c')
		return (print_char(va_arg(*args, int)));
	else if (format == 's')
		return (print_string(va_arg(*args, char *)));
	else if (format == 'p')
		return (print_pointer((unsigned long long)va_arg(*args, void *)));
	else if (format == 'd' || format == 'i')
		return (print_int(va_arg(*args, int)));
	else if (format == 'u')
		return (print_unsigned(va_arg(*args, unsigned int)));
	else if (format == 'x' || format == 'X')
		return (print_hex(format, va_arg(*args, unsigned int)));
	else if (format == '%')
		return (print_char('%'));
	return (0);
}

int	print_formatted(const char *format, ...)
{
	va_list	args;
	int		count;
	int		i;

	if (!format)
		return (0);
	count = 0;
	i = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			i++;
			count += write_format(format[i], &args);
		}
		else
			count += print_char(format[i]);
		i++;
	}
	va_end(args);
	return (count);
}

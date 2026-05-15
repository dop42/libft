/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_console.c */
/*                                                    +:+ +:+         +:+     */
/*   By: lu-value <lu-value@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 00:00:00 by lu-value          #+#    #+#             */
/*   Updated: 2026/04/10 00:00:00 by lu-value         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utility_library.h"
#include <stdio.h>

static int	write_bytes(int fd, const char *buffer, size_t len)
{
	size_t	total;
	ssize_t	written;

	total = 0;
	while (total < len)
	{
		written = write(fd, buffer + total, len - total);
		if (written < 0)
			return (-1);
		total += (size_t)written;
	}
	return ((int)total);
}

static void	get_console_meta(t_console_type type, const char **label,
	const char **color, int *fd)
{
	*label = "SUCCESS";
	*color = CONSOLE_COLOR_SUCCESS;
	*fd = STDOUT_FILENO;
	if (type == CONSOLE_DEBUG)
		*label = "DEBUG";
	else if (type == CONSOLE_INFO)
		*label = "INFO";
	else if (type == CONSOLE_WARN)
		*label = "WARN";
	else if (type == CONSOLE_ERROR)
		*label = "ERROR";
	if (type == CONSOLE_DEBUG)
		*color = CONSOLE_COLOR_DEBUG;
	else if (type == CONSOLE_INFO)
		*color = CONSOLE_COLOR_INFO;
	else if (type == CONSOLE_WARN)
		*color = CONSOLE_COLOR_WARN;
	else if (type == CONSOLE_ERROR)
		*color = CONSOLE_COLOR_ERROR;
	if (type == CONSOLE_WARN || type == CONSOLE_ERROR)
		*fd = STDERR_FILENO;
}

static int	write_message(int fd, const char *format, va_list args)
{
	va_list	copy;
	char	*buffer;
	int		length;
	int		result;

	va_copy(copy, args);
	length = vsnprintf(NULL, 0, format, copy);
	va_end(copy);
	if (length < 0)
		return (-1);
	buffer = malloc((size_t)length + 1);
	if (!buffer)
		return (-1);
	if (vsnprintf(buffer, (size_t)length + 1, format, args) < 0)
		return (free(buffer), -1);
	result = write_bytes(fd, buffer, (size_t)length);
	free(buffer);
	if (result < 0 || write_bytes(fd, "\n", 1) < 0)
		return (-1);
	return (length + 1);
}

static int	write_prefix(int fd, const char *label, const char *color)
{
	int	count;

	count = string_length(color) + string_length(label)
		+ string_length(CONSOLE_COLOR_RESET) + 3;
	if (write_bytes(fd, color, string_length(color)) < 0
		|| write_bytes(fd, "[", 1) < 0
		|| write_bytes(fd, label, string_length(label)) < 0
		|| write_bytes(fd, "]", 1) < 0
		|| write_bytes(fd, CONSOLE_COLOR_RESET,
			string_length(CONSOLE_COLOR_RESET)) < 0
		|| write_bytes(fd, "\n", 1) < 0)
		return (-1);
	return (count);
}

int	write_console(t_console_type type, const char *format, ...)
{
	const char	*label;
	const char	*color;
	va_list		args;
	int			fd;
	int			count;

	get_console_meta(type, &label, &color, &fd);
	count = write_prefix(fd, label, color);
	if (count < 0)
		return (-1);
	if (!format)
		return (count);
	va_start(args, format);
	fd = write_message(fd, format, args);
	va_end(args);
	if (fd < 0)
		return (-1);
	return (count + fd);
}

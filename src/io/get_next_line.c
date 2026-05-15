/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c */
/*                                                    +:+ +:+         +:+     */
/*   By: lu-value <lu-value@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 16:18:23 by lm0uta            #+#    #+#             */
/*   Updated: 2026/03/04 11:18:02 by lu-value         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utility_library.h"

#ifndef OPEN_MAX
# define OPEN_MAX 1024
#endif

static char	*gnl_strjoin(char *stash, char *buffer)
{
	char	*tmp;
	char	*result;

	if (!stash)
		return (duplicate_string(buffer));
	tmp = join_strings(stash, buffer);
	free(stash);
	if (!tmp)
		return (NULL);
	result = tmp;
	return (result);
}

static char	*extract_line(char *stash)
{
	size_t	len;
	char	*newline;

	if (!stash || !*stash)
		return (NULL);
	newline = find_char(stash, '\n');
	if (newline)
		len = (size_t)(newline - stash) + 1;
	else
		len = string_length(stash);
	return (substring(stash, 0, len));
}

static char	*update_stash(char *stash)
{
	size_t	i;
	char	*new_stash;

	if (!stash)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		i++;
	if (!stash[i])
		return (free(stash), NULL);
	new_stash = duplicate_string(stash + i);
	free(stash);
	return (new_stash);
}

static int	read_into_stash(int fd, char *buffer, char **stash)
{
	ssize_t	bytes;

	bytes = read(fd, buffer, BUFFER_SIZE);
	if (bytes == -1)
	{
		free(*stash);
		*stash = NULL;
		return (-1);
	}
	if (bytes == 0)
		return (0);
	buffer[bytes] = '\0';
	*stash = gnl_strjoin(*stash, buffer);
	if (!*stash)
		return (-1);
	return (1);
}

char	*get_next_line(int fd)
{
	static char	*stash[OPEN_MAX];
	char		*buffer;
	char		*line;
	int			status;

	if (fd < 0 || fd >= OPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	status = 1;
	while (status > 0 && (!stash[fd] || !find_char(stash[fd], '\n')))
		status = read_into_stash(fd, buffer, &stash[fd]);
	if (status < 0)
		return (free(buffer), NULL);
	line = extract_line(stash[fd]);
	stash[fd] = update_stash(stash[fd]);
	free(buffer);
	return (line);
}

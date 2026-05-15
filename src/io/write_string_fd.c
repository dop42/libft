/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_string_fd.c */
/*                                                    +:+ +:+         +:+     */
/*   By: lm0uta <lmouta-g@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 13:09:15 by lm0uta            #+#    #+#             */
/*   Updated: 2025/11/12 13:09:23 by lm0uta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utility_library.h"

void	write_string_fd(char *s, int fd)
{
	if (fd < 0 || !s)
		return ;
	write(fd, s, string_length(s));
}

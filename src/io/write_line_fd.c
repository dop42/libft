/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_line_fd.c */
/*                                                    +:+ +:+         +:+     */
/*   By: lm0uta <lmouta-g@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 13:16:49 by lm0uta            #+#    #+#             */
/*   Updated: 2025/11/12 13:17:07 by lm0uta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	write_line_fd(char *s, int fd)
{
	if (fd < 0 || !s)
		return ;
	write_string_fd(s, fd);
	write_char_fd('\n', fd);
}

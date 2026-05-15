/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_node_front.c */
/*                                                    +:+ +:+         +:+     */
/*   By: lm0uta <lmouta-g@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 15:40:53 by lm0uta            #+#    #+#             */
/*   Updated: 2025/11/12 15:41:00 by lm0uta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utility_library.h"

void	add_node_front(t_list **lst, t_list *new_node)
{
	if (!lst || !new_node)
		return ;
	new_node->next = *lst;
	*lst = new_node;
}

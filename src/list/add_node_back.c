/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_node_back.c */
/*                                                    +:+ +:+         +:+     */
/*   By: lm0uta <lmouta-g@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 15:31:00 by lm0uta            #+#    #+#             */
/*   Updated: 2025/11/13 15:31:06 by lm0uta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utility_library.h"

void	add_node_back(t_list **lst, t_list *new_node)
{
	t_list	*tmp;

	if (!lst || !new_node)
		return ;
	if (!(*lst))
	{
		*lst = new_node;
		return ;
	}
	tmp = *lst;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new_node;
}

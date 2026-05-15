/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_list.c */
/*                                                    +:+ +:+         +:+     */
/*   By: lm0uta <lmouta-g@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 16:06:09 by lm0uta            #+#    #+#             */
/*   Updated: 2025/11/13 16:06:12 by lm0uta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utility_library.h"

static void	*free_and_return_null(t_list **result, void (*del)(void *))
{
	if (result)
		clear_list(result, del);
	return (NULL);
}

t_list	*map_list(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*result;
	t_list	*new_node;
	void	*new_content;

	if (!lst || !f || !del)
		return (NULL);
	result = NULL;
	while (lst)
	{
		new_content = f(lst->content);
		new_node = create_node(new_content);
		if (!new_node)
		{
			if (new_content)
				del(new_content);
			return (free_and_return_null(&result, del));
		}
		add_node_back(&result, new_node);
		lst = lst->next;
	}
	return (result);
}

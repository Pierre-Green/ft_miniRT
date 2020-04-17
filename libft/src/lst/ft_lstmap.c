/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 12:04:43 by pguthaus          #+#    #+#             */
/*   Updated: 2019/10/17 16:45:37 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
	void (*del)(void *))
{
	t_list			*result;
	t_list			*node_result;
	t_list			*node;

	node = lst;
	node_result = NULL;
	if (!f || !del)
		return (node_result);
	while (node)
	{
		if (!node_result)
		{
			if (!(result = ft_lstnew(f(node->content))))
				return (NULL);
			node_result = result;
		}
		else
		{
			if (!(node_result->next = ft_lstnew(f(node->content))))
				ft_lstclear(&result, del);
			node_result = node_result->next;
		}
		node = node->next;
	}
	return (result);
}

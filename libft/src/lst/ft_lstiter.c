/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 11:57:33 by pguthaus          #+#    #+#             */
/*   Updated: 2019/10/17 14:53:22 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list			*node;

	node = lst;
	if (!f)
		return ;
	while (node)
	{
		f(node->content);
		node = node->next;
	}
}

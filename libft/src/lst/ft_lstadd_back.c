/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 11:49:58 by pguthaus          #+#    #+#             */
/*   Updated: 2019/10/17 13:52:21 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list			*node;

	node = *alst;
	if (!node)
		*alst = new;
	else
	{
		while (node->next)
			node = node->next;
		node->next = new;
	}
}

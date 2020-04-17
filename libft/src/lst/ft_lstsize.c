/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 11:39:12 by pguthaus          #+#    #+#             */
/*   Updated: 2019/10/08 15:26:09 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_lstsize(t_list *lst)
{
	int				lenght;
	t_list			*node;

	lenght = 0;
	node = lst;
	while (node)
	{
		lenght++;
		node = node->next;
	}
	return (lenght);
}

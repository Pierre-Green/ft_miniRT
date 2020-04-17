/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 11:52:13 by pguthaus          #+#    #+#             */
/*   Updated: 2019/10/17 14:52:20 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst)
	{
		if (lst->content && del)
			del(lst->content);
		free(lst);
	}
}

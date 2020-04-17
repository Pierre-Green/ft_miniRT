/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 11:34:29 by pguthaus          #+#    #+#             */
/*   Updated: 2019/10/18 18:49:34 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				ft_lstadd_front(t_list **alst, t_list *new)
{
	if (!*alst)
		*alst = new;
	else if (new)
	{
		new->next = *alst;
		*alst = new;
	}
}

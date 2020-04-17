/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 17:01:15 by pguthaus          #+#    #+#             */
/*   Updated: 2019/10/07 19:25:42 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrchr(const char *s, int c)
{
	char	*ptr_last;

	ptr_last = NULL;
	while (*s)
	{
		if (*s == c)
			ptr_last = (char *)s;
		s++;
	}
	if (c == 0)
		return ((char *)s);
	return (ptr_last);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 12:10:20 by pguthaus          #+#    #+#             */
/*   Updated: 2019/10/08 19:03:31 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void					*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*dest;
	const unsigned char	*source = src;
	size_t				i;

	if (!dst && !src)
		return (NULL);
	dest = dst;
	if (src <= dst)
	{
		while (len--)
			dest[len] = source[len];
	}
	else
	{
		i = 0;
		while (i++ < len)
			dest[i - 1] = source[i - 1];
	}
	return (dst);
}

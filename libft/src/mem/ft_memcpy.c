/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 12:01:17 by pguthaus          #+#    #+#             */
/*   Updated: 2019/10/07 19:21:32 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*dest;
	size_t			i;

	if (!dst && !src)
		return (NULL);
	dest = dst;
	i = 0;
	while (i < n)
	{
		dest[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dst);
}

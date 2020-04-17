/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 12:04:18 by pguthaus          #+#    #+#             */
/*   Updated: 2019/10/07 19:10:42 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*dest;
	size_t			i;

	dest = dst;
	i = 0;
	while (i < n)
	{
		if ((dest[i] = ((unsigned char *)src)[i]) == (unsigned char)c)
		{
			return (&dest[i + 1]);
		}
		i++;
	}
	return (NULL);
}

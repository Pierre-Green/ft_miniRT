/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 17:12:33 by pguthaus          #+#    #+#             */
/*   Updated: 2019/10/08 16:20:06 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t				ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	const size_t	dst_len = ft_strlen(dst);
	const size_t	src_len = ft_strlen(src);
	size_t			i;

	if (dstsize <= dst_len)
		return (src_len + dstsize);
	i = dst_len;
	while (*src && i < dstsize - 1)
	{
		dst[i] = *src++;
		i++;
	}
	dst[i] = 0;
	return (dst_len + src_len);
}

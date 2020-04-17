/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 15:30:53 by pguthaus          #+#    #+#             */
/*   Updated: 2019/10/08 16:21:31 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	l;

	i = 0;
	if (!*needle)
		return ((char *)haystack);
	while (i < len && haystack[i])
	{
		l = 0;
		while (i + l < len && haystack[i + l] == needle[l])
		{
			if (needle[l + 1] == '\0')
				return ((char *)&(haystack[i]));
			l++;
		}
		i++;
	}
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 15:24:30 by pguthaus          #+#    #+#             */
/*   Updated: 2019/10/17 14:15:05 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		is_in_set(char c, char const *set)
{
	const char	*ptr = set;

	while (*ptr)
	{
		if (*ptr == c)
			return (42);
		ptr++;
	}
	return (0);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	size_t		from;
	size_t		to;
	const char	*ptr = s1;

	from = 0;
	if (!s1)
		return (NULL);
	if (!*s1 || !set)
		return (ft_calloc(1, sizeof(char)));
	while (is_in_set(ptr[from], set))
		from++;
	if (!ptr[from])
		return (ft_calloc(1, sizeof(char)));
	to = ft_strlen(s1) - 1;
	while (is_in_set(ptr[to], set))
		to--;
	return (ft_substr(s1, from, to - from + 1));
}

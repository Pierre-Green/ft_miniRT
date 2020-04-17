/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 14:43:14 by pguthaus          #+#    #+#             */
/*   Updated: 2019/10/17 14:17:06 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*result;
	size_t	i;
	size_t	j;

	if (!s || (result = malloc((len + 1) * sizeof(char))) == NULL)
		return (NULL);
	i = 0;
	while (i < start && s[i])
		i++;
	j = 0;
	while (s[i + j] && j < len)
	{
		result[j] = s[i + j];
		j++;
	}
	result[j] = 0;
	return (result);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 14:51:05 by pguthaus          #+#    #+#             */
/*   Updated: 2019/10/17 14:58:49 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strjoin(char const *s1, char const *s2)
{
	size_t			l1;
	size_t			l2;
	char			*result;

	if (!s1 || !s2)
		return (NULL);
	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	if ((result = malloc((l1 + l2 + 1) * sizeof(char))) == NULL)
		return (NULL);
	ft_memcpy(result, s1, l1);
	ft_memcpy(result + l1, s2, l2);
	result[l1 + l2] = '\0';
	return (result);
}

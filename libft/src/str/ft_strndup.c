/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 19:43:00 by pguthaus          #+#    #+#             */
/*   Updated: 2020/01/07 19:43:57 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strndup(const char *s1, size_t n)
{
	char			*result;

	if ((result = ft_calloc(n + 1, sizeof(char))) == NULL)
		return (NULL);
	ft_memcpy(result, s1, n);
	return (result);
}

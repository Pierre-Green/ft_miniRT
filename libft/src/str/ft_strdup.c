/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 17:57:28 by pguthaus          #+#    #+#             */
/*   Updated: 2019/10/07 18:00:21 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strdup(const char *s1)
{
	const size_t	len = ft_strlen(s1);
	char			*result;

	if ((result = ft_calloc(len + 1, sizeof(char))) == NULL)
		return (NULL);
	ft_memcpy(result, s1, len);
	return (result);
}

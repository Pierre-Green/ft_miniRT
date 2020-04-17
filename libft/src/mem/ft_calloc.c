/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 12:58:57 by pguthaus          #+#    #+#             */
/*   Updated: 2019/10/07 15:02:35 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_calloc(size_t count, size_t size)
{
	const size_t	total_size = count * size;
	unsigned char	*ptr;

	if ((ptr = malloc(total_size)) == NULL)
		return (NULL);
	ft_bzero(ptr, total_size);
	return (ptr);
}

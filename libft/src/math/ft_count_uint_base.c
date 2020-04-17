/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_uint_base.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 16:33:55 by pguthaus          #+#    #+#             */
/*   Updated: 2019/10/25 17:08:21 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t				ft_count_uint_base(uint64_t n, uint32_t base)
{
	uint32_t		pow;

	pow = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		pow++;
		n /= base;
	}
	return (pow);
}

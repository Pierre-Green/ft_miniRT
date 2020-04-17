/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_idkpow.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 16:44:17 by pguthaus          #+#    #+#             */
/*   Updated: 2019/10/08 17:02:57 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t			ft_idkpow(int n, int powa)
{
	const int	t = n;

	if (powa == 0 || n == 0)
		return (1);
	while (--powa > 0)
		n *= t;
	return ((size_t)n);
}

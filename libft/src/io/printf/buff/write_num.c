/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 14:35:31 by pguthaus          #+#    #+#             */
/*   Updated: 2019/11/26 00:57:32 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf/buff.h"

size_t				buff_write_int(t_buff *buff, int n)
{
	const char		sign = n >= 0 ? 0 : '-';
	size_t			count;

	count = 0;
	if (sign)
	{
		count += buff_write_uchar(buff, '-');
		count += buff_write_uint(buff, (unsigned int)(n) * -1);
	}
	else
		count += buff_write_uint(buff, (unsigned int)n);
	return (count);
}

size_t				buff_write_uint(t_buff *buff, unsigned int n)
{
	char			t_buff[10];
	size_t			pow;
	size_t			i;

	pow = ft_count_uint_base(n, 10);
	i = pow;
	while (i)
	{
		t_buff[i - 1] = (n % 10) + '0';
		n /= 10;
		i--;
	}
	while (i < pow)
		buff_write_uchar(buff, t_buff[i++]);
	return (pow);
}

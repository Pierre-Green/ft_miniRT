/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 15:30:38 by pguthaus          #+#    #+#             */
/*   Updated: 2019/11/26 00:57:32 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf/buff.h"

size_t					buff_write_hex(t_buff *buff, unsigned long int n,
	char uppercase)
{
	char				t_buff[16];
	size_t				i;
	unsigned long int	tmp;

	i = 0;
	if (!n)
		return (buff_write_uchar(buff, '0'));
	while (n)
	{
		tmp = n % 16;
		if (tmp < 10)
			t_buff[i] = tmp + 48;
		else
			t_buff[i] = (uppercase ? tmp + 55 : tmp + 87);
		i++;
		n /= 16;
	}
	tmp = i;
	while (tmp > 0)
	{
		buff_write_uchar(buff, t_buff[tmp - 1]);
		tmp--;
	}
	return (i);
}

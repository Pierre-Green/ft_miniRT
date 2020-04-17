/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 15:29:13 by pguthaus          #+#    #+#             */
/*   Updated: 2019/10/25 17:13:37 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void			ft_int_min(int fd)
{
	ft_putstr_fd("-2147483648", fd);
}

void				ft_putnbr_fd(int n, int fd)
{
	const size_t	len = ft_count_uint_base(n, 10);
	char			buff[11];
	size_t			i;
	int				tmp;

	if (n == INT32_MIN)
		return (ft_int_min(fd));
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = -n;
	}
	ft_bzero(buff, 11);
	i = 0;
	while (i < len)
	{
		tmp = n / ft_idkpow(10, len - i - 1);
		buff[i] = tmp % 10 + '0';
		i++;
	}
	ft_putstr_fd(buff, fd);
}

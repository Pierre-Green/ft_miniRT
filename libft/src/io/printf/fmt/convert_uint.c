/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_uint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 20:10:43 by pguthaus          #+#    #+#             */
/*   Updated: 2019/11/26 00:58:02 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf/fmt.h"
#include "printf/buff.h"

static size_t			write_uint(unsigned int value, t_buff *buff,
	size_t len)
{
	size_t				count;

	count = 0;
	if (len)
	{
		count += buff_write_nchar(buff,
			len - ft_count_uint_base(value, 10), '0');
		count += buff_write_uint(buff, value);
	}
	return (count);
}

static void				convert_uint_negativ(t_state *state, t_fmt fmt,
	size_t len)
{
	size_t				minwidth;

	minwidth = MAX(len, fmt.minwidth);
	state->count += write_uint(fmt.value.u, state->buff, len);
	state->count += buff_write_nchar(state->buff, minwidth - len, ' ');
}

static void				convert_uint_zeropad(t_state *state, t_fmt fmt,
	size_t len)
{
	size_t				minwidth;

	minwidth = MAX(len, fmt.minwidth);
	state->count += write_uint(fmt.value.u, state->buff, minwidth);
}

static void				convert_uint_default(t_state *state, t_fmt fmt,
	size_t len)
{
	size_t				minwidth;

	minwidth = MAX(len, fmt.minwidth);
	state->count += buff_write_nchar(state->buff, minwidth - len, ' ')
		+ write_uint(fmt.value.u, state->buff, len);
}

void					convert_uint(t_state *state, t_fmt fmt)
{
	const unsigned int	value = fmt.value.u;
	size_t				len;

	len = ft_count_uint_base(value, 10);
	if (fmt.precision >= 0)
		len = MAX(len, (size_t)fmt.precision);
	else if (fmt.precision < 0)
		fmt.minwidth = ABS(fmt.precision);
	if (value == 0 && fmt.precised && fmt.precision == 0)
		len = 0;
	if (fmt.flags & FLAG_NEGATIV || fmt.precision < 0)
		convert_uint_negativ(state, fmt, len);
	else if (fmt.flags & FLAG_ZEROPAD && !fmt.precised)
		convert_uint_zeropad(state, fmt, len);
	else
		convert_uint_default(state, fmt, len);
}

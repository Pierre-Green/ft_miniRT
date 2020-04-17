/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 20:13:41 by pguthaus          #+#    #+#             */
/*   Updated: 2019/11/26 00:58:02 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf/fmt.h"
#include "printf/buff.h"

static size_t				write_hex(t_buff *buff, unsigned int value,
	size_t zero_len)
{
	size_t					count;

	count = 0;
	count += buff_write_nchar(buff, zero_len, '0')
		+ buff_write_hex(buff, value, 0);
	return (count);
}

static void					convert_hex_negativ(t_state *state, t_fmt fmt,
	size_t len)
{
	const size_t			minwidth = MAX(len, fmt.minwidth);
	const unsigned int		value = fmt.value.u;
	const size_t			count = ft_count_uint_base(value, 16);

	state->count += write_hex(state->buff, value, len - count)
		+ buff_write_nchar(state->buff, minwidth - len, ' ');
}

static void					convert_hex_zeropad(t_state *state, t_fmt fmt,
	size_t len)
{
	const size_t			minwidth = MAX(len, fmt.minwidth);
	const unsigned int		value = fmt.value.u;

	state->count += write_hex(state->buff, value, minwidth - len);
}

static void					convert_hex_default(t_state *state, t_fmt fmt,
	size_t len)
{
	const size_t			minwidth = MAX(len, fmt.minwidth);
	const unsigned int		value = fmt.value.u;
	const size_t			count = ft_count_uint_base(value, 16);

	if (fmt.precision < 0)
		return (convert_hex_negativ(state, fmt, len));
	state->count += buff_write_nchar(state->buff, minwidth - len, ' ');
	if (len)
		state->count += write_hex(state->buff, value, len - count);
}

void						convert_hex(t_state *state, t_fmt fmt)
{
	size_t					len;

	len = ft_count_uint_base(fmt.value.u, 16);
	if (fmt.precision >= 0)
		len = MAX(len, (size_t)fmt.precision);
	if (fmt.value.u == 0 && fmt.precised && !fmt.precision)
		len = 0;
	if (fmt.precision < 0)
		fmt.minwidth = ABS(fmt.precision);
	if (fmt.flags & FLAG_NEGATIV || (fmt.negprec && fmt.precision == 0))
		convert_hex_negativ(state, fmt, len);
	else if (fmt.flags & FLAG_ZEROPAD && !fmt.precised)
		convert_hex_zeropad(state, fmt, len);
	else
		convert_hex_default(state, fmt, len);
}

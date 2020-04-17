/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 20:10:43 by pguthaus          #+#    #+#             */
/*   Updated: 2019/11/26 00:58:02 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf/fmt.h"
#include "printf/buff.h"

static size_t		write_int(int value, t_buff *buff, size_t len,
	size_t minwidth)
{
	unsigned int	u_value;
	size_t			count;

	count = 0;
	u_value = (unsigned int)value;
	if (value < 0)
	{
		len++;
		count += buff_write_uchar(buff, '-');
		u_value = (unsigned int)(value) * -1;
	}
	if (minwidth)
	{
		count += buff_write_nchar(buff, minwidth - len, '0');
		count += buff_write_uint(buff, u_value);
	}
	return (count);
}

static void			convert_int_negativ(t_state *state, t_fmt fmt, size_t len)
{
	const int		value = fmt.value.i;
	size_t			minwidth;
	size_t			count;

	count = ft_count_uint_base((unsigned int)ABS(value), 10);
	if (fmt.precision < 0)
		fmt.minwidth = 0;
	minwidth = MAX(len, fmt.minwidth);
	if (fmt.precision < 0)
		minwidth = MAX(minwidth, (size_t)(fmt.precision * -1));
	state->count += write_int(value, state->buff, count, len)
		+ buff_write_nchar(state->buff, minwidth - len, ' ');
}

static void			convert_int_zeropad(t_state *state, t_fmt fmt)
{
	const int		value = fmt.value.i;
	size_t			len;
	size_t			minwidth;

	len = ft_count_uint_base((unsigned int)ABS(value), 10);
	minwidth = MAX(len, fmt.minwidth);
	state->count += write_int(value, state->buff, len, minwidth);
}

static void			convert_int_default(t_state *state, t_fmt fmt, size_t len)
{
	const int		value = fmt.value.i;
	size_t			minwidth;
	size_t			count;

	count = ft_count_uint_base((unsigned int)ABS(value), 10);
	minwidth = MAX(len, fmt.minwidth);
	if (fmt.precision < 0)
		convert_int_negativ(state, fmt, len);
	else
		state->count += buff_write_nchar(state->buff, minwidth - len, ' ')
			+ write_int(value, state->buff, count, len);
}

void				convert_int(t_state *state, t_fmt fmt)
{
	size_t			len;

	len = ft_count_uint_base(ABS(fmt.value.i), 10);
	if (fmt.precision >= 0)
		len = MAX(len, (size_t)fmt.precision);
	if (fmt.value.i == 0 && fmt.precised && fmt.precision == 0)
		len = 0;
	if (fmt.value.i < 0)
		len++;
	if (fmt.flags & FLAG_NEGATIV)
		convert_int_negativ(state, fmt, len);
	else if (fmt.flags & FLAG_ZEROPAD && !fmt.precised)
		convert_int_zeropad(state, fmt);
	else
		convert_int_default(state, fmt, len);
}

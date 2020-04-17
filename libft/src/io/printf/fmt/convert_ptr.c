/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_ptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 18:36:36 by pguthaus          #+#    #+#             */
/*   Updated: 2019/11/26 00:58:02 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf/fmt.h"

static size_t		write_ptr(t_buff *buff, unsigned long int val,
	size_t minlen, t_bool none)
{
	size_t			count;
	size_t			len;

	count = 0;
	len = PTR_LEN;
	if (!val)
		len = 1;
	count += buff_write_strl(buff, "0x", 2);
	count += buff_write_nchar(buff, minlen - len, '0');
	if (!none)
		count += buff_write_hex(buff, val, false);
	return (count);
}

static void			convert_ptr_negativ(t_state *state, t_fmt fmt, size_t len,
	t_bool none)
{
	size_t			minwidth;
	size_t			minlen;

	minwidth = MAX(len, fmt.minwidth);
	minlen = len - 2;
	if (fmt.precision > 0)
		minlen = MAX((size_t)fmt.precision, minlen);
	state->count += write_ptr(state->buff, fmt.value.u, minlen, none);
	state->count += buff_write_nchar(state->buff, minwidth - len, ' ');
}

static void			convert_ptr_zeropad(t_state *state, t_fmt fmt, size_t len,
	t_bool none)
{
	state->count += write_ptr(state->buff, fmt.value.u,
		MAX(len, fmt.minwidth) - 2, none);
}

static void			convert_ptr_default(t_state *state, t_fmt fmt, size_t len,
	t_bool none)
{
	size_t			minwidth;

	minwidth = MAX(len, fmt.minwidth);
	state->count += buff_write_nchar(state->buff, minwidth - len, ' ');
	state->count += write_ptr(state->buff, fmt.value.u,
		MAX(len - 2, (size_t)fmt.precision), none);
}

void				convert_ptr(t_state *state, t_fmt fmt)
{
	size_t			len;
	t_bool			none;

	len = PTR_LEN + 2;
	none = false;
	if (!fmt.value.u)
		len = 3;
	if (!fmt.value.u && fmt.precised && !fmt.precision)
		none = true;
	if (fmt.precision >= 0)
		len = MAX(len, (size_t)fmt.precision);
	if (fmt.precision < 0)
		fmt.minwidth = ABS(fmt.precision);
	if (fmt.flags & FLAG_NEGATIV || fmt.precision < 0)
		convert_ptr_negativ(state, fmt, len, none);
	else if (fmt.flags & FLAG_ZEROPAD && !fmt.precised)
		convert_ptr_zeropad(state, fmt, len, none);
	else
		convert_ptr_default(state, fmt, len, none);
}

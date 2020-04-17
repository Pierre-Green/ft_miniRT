/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 17:59:45 by pguthaus          #+#    #+#             */
/*   Updated: 2019/11/26 00:58:02 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf/fmt.h"
#include "printf/buff.h"

static void		convert_char_negativ(t_state *state, t_fmt fmt, size_t minwidth)
{
	state->count += buff_write_uchar(state->buff, fmt.value.i);
	state->count += buff_write_nchar(state->buff, minwidth - 1, ' ');
}

static void		convert_char_zeropad(t_state *state, t_fmt fmt, size_t minwidth)
{
	state->count += buff_write_nchar(state->buff, minwidth - 1, '0');
	state->count += buff_write_uchar(state->buff, fmt.value.i);
}

static void		convert_char_default(t_state *state, t_fmt fmt, size_t minwidth)
{
	state->count += buff_write_nchar(state->buff, minwidth - 1, ' ');
	state->count += buff_write_uchar(state->buff, fmt.value.i);
}

void			convert_char(t_state *state, t_fmt fmt)
{
	size_t		minwidth;

	if (fmt.precision < 0)
		fmt.minwidth = ABS(fmt.precision);
	minwidth = MAX(fmt.minwidth, 1);
	if (fmt.flags & FLAG_NEGATIV || fmt.precision < 0)
		convert_char_negativ(state, fmt, minwidth);
	else if (fmt.flags & FLAG_ZEROPAD)
		convert_char_zeropad(state, fmt, minwidth);
	else
		convert_char_default(state, fmt, minwidth);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 20:06:38 by pguthaus          #+#    #+#             */
/*   Updated: 2019/11/26 00:58:02 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf/fmt.h"
#include "printf/buff.h"

static size_t		fmt_strlen(char *str, t_fmt fmt)
{
	size_t			i;

	i = 0;
	if (!str)
		i = 6;
	else
		while (*(str + i))
			i++;
	return ((fmt.precised ? MIN(i, (size_t)fmt.precision) : i));
}

static void			convert_str_negativ(t_state *state, t_fmt fmt, size_t len)
{
	size_t			minwidth;

	minwidth = MAX(len, fmt.minwidth);
	if (fmt.value.s)
		state->count += buff_write_strl(state->buff, fmt.value.s, len);
	else
		state->count += buff_write_strl(state->buff, STR_NULL, len);
	state->count += buff_write_nchar(state->buff, minwidth - len, ' ');
}

static void			convert_str_zeropad(t_state *state, t_fmt fmt, size_t len)
{
	size_t			minwidth;

	minwidth = MAX(len, fmt.minwidth);
	state->count += buff_write_nchar(state->buff, minwidth - len, '0');
	if (fmt.value.s)
		state->count += buff_write_strl(state->buff, fmt.value.s, len);
	else
		state->count += buff_write_strl(state->buff, STR_NULL, len);
}

static void			convert_str_default(t_state *state, t_fmt fmt, size_t len)
{
	size_t			minwidth;

	minwidth = MAX(len, fmt.minwidth);
	state->count += buff_write_nchar(state->buff, minwidth - len, ' ');
	if (fmt.value.s)
		state->count += buff_write_strl(state->buff, fmt.value.s, len);
	else
		state->count += buff_write_strl(state->buff, STR_NULL, len);
}

void				convert_str(t_state *state, t_fmt fmt)
{
	const size_t	len = fmt_strlen(fmt.value.s, fmt);

	if (fmt.precision < 0)
		state->count += buff_write_nchar(state->buff, ABS(fmt.precision), ' ');
	else
	{
		if (fmt.flags & FLAG_NEGATIV)
			convert_str_negativ(state, fmt, len);
		else if (fmt.flags & FLAG_ZEROPAD)
			convert_str_zeropad(state, fmt, len);
		else
			convert_str_default(state, fmt, len);
	}
}

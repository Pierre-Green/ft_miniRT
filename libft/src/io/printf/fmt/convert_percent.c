/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_percent.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 12:36:49 by pguthaus          #+#    #+#             */
/*   Updated: 2019/11/26 00:58:02 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf/fmt.h"

void						convert_percent(t_state *state, t_fmt fmt)
{
	size_t					offset;

	offset = 0;
	if (fmt.precision < 0)
		fmt.minwidth = ABS(fmt.precision);
	if (fmt.minwidth)
		offset = fmt.minwidth - 1;
	if (fmt.flags & FLAG_NEGATIV || fmt.precision < 0)
		state->count += buff_write_uchar(state->buff, '%')
			+ buff_write_nchar(state->buff, offset, ' ');
	else if (fmt.flags & FLAG_ZEROPAD)
		state->count += buff_write_nchar(state->buff, offset, '0')
			+ buff_write_uchar(state->buff, '%');
	else
		state->count += buff_write_nchar(state->buff, offset, ' ')
			+ buff_write_uchar(state->buff, '%');
}

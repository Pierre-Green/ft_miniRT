/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fmt.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 15:54:03 by pguthaus          #+#    #+#             */
/*   Updated: 2020/04/17 17:19:22 by pguthaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf/fmt.h"

static t_flag				g_flags[1 << 7] = {
	['0'] = FLAG_ZEROPAD,
	['-'] = FLAG_NEGATIV
};
static t_convert_func		g_conversions[1 << 7] = {
	['c'] = convert_char,
	['s'] = convert_str,
	['p'] = convert_ptr,
	['d'] = convert_int,
	['i'] = convert_int,
	['u'] = convert_uint,
	['x'] = convert_hex,
	['X'] = convert_hex_up,
	['%'] = convert_percent
};
static t_convert_valu		g_values[1 << 7] = {
	['c'] = value_int,
	['s'] = value_str,
	['p'] = value_ptr,
	['d'] = value_int,
	['i'] = value_int,
	['u'] = value_uint,
	['x'] = value_uint,
	['X'] = value_uint
};

static t_fmt		get_initial_fmt(void)
{
	return ((t_fmt){ 0, 0, 0, 0, 0, { 0 } });
}

static t_fmt		parse_flags(t_state *state, t_fmt fmt)
{
	t_flag			flag;

	while ((flag = g_flags[(unsigned char)*state->frmt]))
	{
		fmt.flags |= flag;
		state->frmt++;
	}
	return (fmt);
}

static t_fmt		parse_minwidth(t_state *state, t_fmt fmt)
{
	if (*state->frmt == '*')
	{
		fmt.minwidth = va_arg(state->args, unsigned int);
		state->frmt++;
	}
	else
		while (*state->frmt >= '0' && *state->frmt <= '9')
		{
			fmt.minwidth *= 10;
			fmt.minwidth += (*state->frmt) - '0';
			state->frmt++;
		}
	return (fmt);
}

static t_fmt		parse_precision(t_state *state, t_fmt fmt)
{
	if (*state->frmt && *state->frmt == '.')
	{
		state->frmt++;
		fmt.precised = 42;
		if (*state->frmt == '*')
		{
			fmt.precision = va_arg(state->args, int);
			state->frmt++;
		}
		else
		{
			if (*state->frmt == '-' && state->frmt++)
				fmt.negprec = 42;
			while (*state->frmt >= '0' && *state->frmt <= '9')
			{
				fmt.precision *= 10;
				fmt.precision += (*state->frmt) - '0';
				state->frmt++;
			}
			fmt.precision = (fmt.negprec ? fmt.precision * -1 : fmt.precision);
		}
	}
	return (fmt);
}

void				fmt(t_state *state)
{
	t_fmt			fmt;
	t_convert_func	f_conv;
	t_convert_valu	f_valu;

	state->frmt++;
	fmt = get_initial_fmt();
	fmt = parse_flags(state, fmt);
	fmt = parse_minwidth(state, fmt);
	fmt = parse_precision(state, fmt);
	if (!(f_conv = g_conversions[(unsigned char)*state->frmt]))
		return ;
	if ((f_valu = g_values[(unsigned char)*state->frmt]))
		fmt = f_valu(state, fmt);
	f_conv(state, fmt);
	state->frmt++;
}

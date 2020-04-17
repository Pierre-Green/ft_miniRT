/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   values.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 18:34:02 by pguthaus          #+#    #+#             */
/*   Updated: 2019/11/26 00:58:02 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf/fmt.h"

t_fmt						value_int(t_state *state, t_fmt fmt)
{
	fmt.value.i = va_arg(state->args, int);
	return (fmt);
}

t_fmt						value_str(t_state *state, t_fmt fmt)
{
	fmt.value.s = va_arg(state->args, char *);
	return (fmt);
}

t_fmt						value_ptr(t_state *state, t_fmt fmt)
{
	fmt.value.p = va_arg(state->args, void *);
	return (fmt);
}

t_fmt						value_uint(t_state *state, t_fmt fmt)
{
	fmt.value.u = va_arg(state->args, unsigned int);
	return (fmt);
}

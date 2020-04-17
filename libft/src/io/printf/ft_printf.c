/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 15:19:13 by pguthaus          #+#    #+#             */
/*   Updated: 2019/11/26 00:59:25 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "printf/fmt.h"

static t_state	*get_initial_state(const char *format, va_list args)
{
	t_state		*state;

	if (!(state = (t_state *)malloc(sizeof(t_state))))
		return (NULL);
	state->count = 0;
	state->frmt = (char *)format;
	va_copy(state->args, args);
	if (!(state->buff = (t_buff *)malloc(sizeof(t_buff))))
	{
		clear_state(state);
		return (NULL);
	}
	state->buff->len = 0;
	return (state);
}

int				ft_printf_va(const char *format, va_list args)
{
	t_state		*state;
	size_t		count;

	if (!(state = get_initial_state(format, args)))
		return (-42);
	while (*state->frmt)
	{
		if (*state->frmt == '%')
			fmt(state);
		else
		{
			while (*state->frmt && *state->frmt != '%')
			{
				state->count += buff_write_uchar(state->buff,
					(unsigned char)*state->frmt);
				state->frmt++;
			}
		}
	}
	buff_flush(state->buff);
	count = state->count;
	clear_state(state);
	return (count);
}

int				ft_printf(const char *format, ...)
{
	va_list		args;
	int			result;

	va_start(args, format);
	result = ft_printf_va(format, args);
	va_end(args);
	return (result);
}

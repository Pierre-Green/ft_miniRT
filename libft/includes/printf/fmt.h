/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fmt.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 15:54:11 by pguthaus          #+#    #+#             */
/*   Updated: 2020/04/17 17:19:20 by pguthaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FMT_H
# define FMT_H
# include <stdint.h>
# include <stdlib.h>
# include "state.h"
# include "libft.h"
# define FLAG_ZEROPAD 0x0F000000
# define FLAG_NEGATIV 0x00F00000
# define OUT_NULL "(null)"
# define PTR_LEN 12
# define STR_NULL "(null)"

typedef uint32_t			t_flag;

typedef struct				s_fmt
{
	t_flag					flags;
	size_t					minwidth;
	char					precised;
	ssize_t					precision;
	char					negprec;
	union					u_value
	{
		long int			i;
		unsigned long int	u;
		char				*s;
		void				*p;
	}						value;

}							t_fmt;
void						fmt(t_state *state);

typedef void				(*t_convert_func)(t_state *, t_fmt);
typedef t_fmt				(*t_convert_valu)(t_state *, t_fmt);
void						convert_char(t_state *state, t_fmt fmt);
void						convert_str(t_state *state, t_fmt fmt);
void						convert_ptr(t_state *state, t_fmt fmt);
void						convert_int(t_state *state, t_fmt fmt);
void						convert_uint(t_state *state, t_fmt fmt);
void						convert_hex(t_state *state, t_fmt fmt);
void						convert_hex_up(t_state *state, t_fmt fmt);
void						convert_percent(t_state *state, t_fmt fmt);
t_fmt						value_int(t_state *state, t_fmt fmt);
t_fmt						value_str(t_state *state, t_fmt fmt);
t_fmt						value_ptr(t_state *state, t_fmt fmt);
t_fmt						value_uint(t_state *state, t_fmt fmt);

#endif

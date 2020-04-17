/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolution.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 06:41:09 by pguthaus          #+#    #+#             */
/*   Updated: 2020/01/06 19:42:13 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void					parse_resolution(char *line, t_carry *c)
{
	const t_line_spec	specs[3] = { INT, INT, NONE };
	t_line_result		*results;

	results = parse_line_specs(line, (t_line_spec *)specs, 1, c);
	c->w->res[0] = results[0].i;
	c->w->res[1] = results[1].i;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolution.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 06:41:09 by pguthaus          #+#    #+#             */
/*   Updated: 2020/04/17 18:45:51 by pguthaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void					parse_resolution(char *line, t_carry *c)
{
	const t_line_spec	specs[3] = { INT, INT, NONE };
	t_line_result		*results;

	if (!(results = parse_line_specs(line, (t_line_spec *)specs, 1, c)))
		freexit(-42, "Allocation error", c);
	c->w->res[0] = results[0].i;
	c->w->res[1] = results[1].i;
	free((void *)results);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambiant_light.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 06:42:13 by pguthaus          #+#    #+#             */
/*   Updated: 2020/01/06 19:50:56 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "minirt.h"

void					parse_ambiant_light(char *line, t_carry *c)
{
	const t_line_spec	specs[3] = { FLOAT, COLOR, NONE };
	t_line_result		*results;

	results = parse_line_specs(line, (t_line_spec *)specs, 1, c);
	if (!(c->w->ambiant_light = malloc(sizeof(t_ambiant_light))))
		freexit(23, "File format error", c);
	if (results[0].f < 0.0f || results[0].f > 1.0f)
		freexit(24, "File format error", c);
	c->w->ambiant_light->ratio = results[0].f;
	c->w->ambiant_light->color = results[1].color;
}

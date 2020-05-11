/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_light.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 15:38:07 by pguthaus          #+#    #+#             */
/*   Updated: 2020/05/11 15:38:08 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "minirt.h"

void					parse_light(char *line, t_carry *c)
{
	const t_line_spec	specs[4] = { VEC3F, FLOAT, COLOR, NONE };
	t_line_result		*results;
	t_light				*lights[c->w->lights_count];
	unsigned int		i;

	if (!(results = parse_line_specs(line, (t_line_spec *)specs, 1, c)))
		freexit(-42, "Allocation error", c);
	i = 0;
	while (i < c->w->lights_count && (lights[i] = c->w->lights[i]))
		i++;
	free(c->w->lights);
	if (!(c->w->lights = malloc(sizeof(t_light *) * i)))
		freexit(-42, "Allocation failed", c);
	i = 0;
	while (i < c->w->lights_count && (c->w->lights[i] = lights[i]))
		i++;
	if (!(c->w->lights[i] = malloc(sizeof(t_light))))
		freexit(-42, "Allocation failed", c);
	c->w->lights[i]->position = results[0].vec3f;
	c->w->lights[i]->ratio = results[1].f;
	c->w->lights[i]->color = results[2].color;
	c->w->lights_count++;
	free((void *)results);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 02:32:27 by pguthaus          #+#    #+#             */
/*   Updated: 2020/04/17 18:47:06 by pguthaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "minirt.h"

void					parse_square(char *line, t_carry *c)
{
	const t_line_spec	specs[5] = { VEC3F, NVEC3F, FLOAT, COLOR, NONE };
	t_line_result		*results;
	t_obj				*obj;

	if (!(results = parse_line_specs(line, (t_line_spec *)specs, 2, c)))
		freexit(-42, "Allocation error", c);
	if (!(obj = malloc(sizeof(t_obj))))
		freexit(-42, "Allocation failed", c);
	obj->type = SQUARE;
	obj->obj.square = (t_square){	results[0].vec3f, results[1].vec3f,
									results[2].f, results[3].color };
	add_obj(obj, c);
	free((void *)results);
}

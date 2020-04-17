/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 02:32:54 by pguthaus          #+#    #+#             */
/*   Updated: 2020/04/17 18:44:08 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "minirt.h"

void					parse_cylinder(char *line, t_carry *c)
{
	const t_line_spec	specs[6] = { VEC3F, NVEC3F, FLOAT, FLOAT, COLOR, NONE };
	t_line_result		*results;
	t_obj				*obj;

	if (!(results = parse_line_specs(line, (t_line_spec *)specs, 2, c)))
		freexit(-42, "Allocation error", c);
	if (!(obj = malloc(sizeof(t_obj))))
		freexit(-42, "Allocation failed", c);
	obj->type = CYLINDER;
	obj->obj.cylinder = (t_cylinder){	results[0].vec3f, results[1].vec3f,
										results[2].f, results[2].f / 2, results[3].f, results[4].color };
	add_obj(obj, c);
	free((void *)results);
}

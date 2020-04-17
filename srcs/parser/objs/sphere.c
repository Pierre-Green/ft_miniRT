/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 02:22:06 by pguthaus          #+#    #+#             */
/*   Updated: 2020/04/17 18:46:30 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "minirt.h"

void					parse_sphere(char *line, t_carry *c)
{
	const t_line_spec	specs[4] = { VEC3F, FLOAT, COLOR, NONE };
	t_line_result		*results;
	t_obj				*obj;

	if (!(results = parse_line_specs(line, (t_line_spec *)specs, 2, c)))
		freexit(-42, "Allocation error", c);
	if (!(obj = malloc(sizeof(t_obj))))
		freexit(-42, "Allocation failed", c);
	obj->type = SPHERE;
	obj->obj.sphere = (t_sphere){ results[0].vec3f, results[1].f, results[2].color };
	add_obj(obj, c);
	free((void *)results);
}

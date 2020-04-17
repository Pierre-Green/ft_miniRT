/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 02:22:06 by pguthaus          #+#    #+#             */
/*   Updated: 2020/01/06 19:41:15 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "minirt.h"

void					parse_sphere(char *line, t_carry *c)
{
	const t_line_spec	specs[4] = { VEC3F, FLOAT, COLOR, NONE };
	t_line_result		*res;
	t_obj				*obj;

	res = parse_line_specs(line, (t_line_spec *)specs, 2, c);
	if (!(obj = malloc(sizeof(t_obj))))
		freexit(-42, "Allocation failed", c);
	obj->type = SPHERE;
	obj->obj.sphere = (t_sphere){ res[0].vec3f, res[1].f, res[2].color };
	add_obj(obj, c);
}

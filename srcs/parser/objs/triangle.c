/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 02:33:14 by pguthaus          #+#    #+#             */
/*   Updated: 2020/01/06 19:41:15 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "minirt.h"

void					parse_triangle(char *line, t_carry *c)
{
	const t_line_spec	specs[5] = { VEC3F, VEC3F, VEC3F, COLOR, NONE };
	t_line_result		*res;
	t_obj				*obj;

	res = parse_line_specs(line, (t_line_spec *)specs, 2, c);
	if (!(obj = malloc(sizeof(t_obj))))
		freexit(-42, "Allocation failed", c);
	obj->type = TRIANGLE;
	obj->obj.triangle = (t_triangle){	res[0].vec3f, res[1].vec3f,
										res[2].vec3f,
										ft_vec3f_cross(ft_vec3f_sub(res[1].vec3f, res[0].vec3f), ft_vec3f_sub(res[2].vec3f, res[0].vec3f)),
										res[3].color };
	add_obj(obj, c);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 02:33:14 by pguthaus          #+#    #+#             */
/*   Updated: 2020/04/17 18:48:04 by pguthaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "minirt.h"

void					parse_triangle(char *line, t_carry *c)
{
	const t_line_spec	specs[5] = { VEC3F, VEC3F, VEC3F, COLOR, NONE };
	t_line_result		*results;
	t_obj				*obj;

	if (!(results = parse_line_specs(line, (t_line_spec *)specs, 2, c)))
		freexit(-42, "Allocation error", c);
	if (!(obj = malloc(sizeof(t_obj))))
		freexit(-42, "Allocation failed", c);
	obj->type = TRIANGLE;
	obj->obj.triangle = (t_triangle){	results[0].vec3f, results[1].vec3f,
										results[2].vec3f,
										ft_vec3f_cross(ft_vec3f_sub(results[1].vec3f, results[0].vec3f), ft_vec3f_sub(results[2].vec3f, results[0].vec3f)),
										results[3].color };
	add_obj(obj, c);
	free((void *)results);
}

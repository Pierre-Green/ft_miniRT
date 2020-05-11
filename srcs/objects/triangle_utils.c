/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 20:50:34 by pguthaus          #+#    #+#             */
/*   Updated: 2020/05/11 15:45:34 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "parser.h"

/*
** Point A: vec3f
** Point B: vec3f
** Point C: vec3f
** Color: Color
*/

void	new_triangle(t_triangle *dest, t_line_result *results)
{
	dest->a = results[0].vec3f;
	dest->b = results[1].vec3f;
	dest->c = results[2].vec3f;
	dest->color = results[3].color;
	dest->ab = v3f_sub(dest->b, dest->a);
	dest->ac = v3f_sub(dest->c, dest->a);
	dest->dot_abab = v3f_dot(dest->ab, dest->ab);
	dest->dot_abac = v3f_dot(dest->ab, dest->ac);
	dest->dot_acac = v3f_dot(dest->ac, dest->ac);
	dest->calcul_d = dest->dot_abac * dest->dot_abac - dest->dot_abab
		* dest->dot_acac;
	dest->normal = v3f_normalize(v3f_cross(dest->ab, dest->ac));
}

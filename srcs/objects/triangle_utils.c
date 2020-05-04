/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 20:50:34 by pguthaus          #+#    #+#             */
/*   Updated: 2020/05/04 15:47:58 by pguthaus         ###   ########.fr       */
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
	dest->ab = ft_vec3f_sub(dest->b, dest->a);
	dest->ac = ft_vec3f_sub(dest->c, dest->a);
	dest->dot_abab = ft_vec3f_dot(dest->ab, dest->ab);
	dest->dot_abac = ft_vec3f_dot(dest->ab, dest->ac);
	dest->dot_acac = ft_vec3f_dot(dest->ac, dest->ac);
	dest->calcul_d = dest->dot_abac * dest->dot_abac - dest->dot_abab * dest->dot_acac;
	dest->normal = ft_vec3f_normalize(ft_vec3f_cross(dest->ab, dest->ac));
}

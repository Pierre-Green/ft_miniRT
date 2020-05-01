/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 20:50:34 by pguthaus          #+#    #+#             */
/*   Updated: 2020/05/01 21:24:31 by pguthaus         ###   ########.fr       */
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
	dest->normal = ft_vec3f_cross(dest->ab, dest->ac);
}

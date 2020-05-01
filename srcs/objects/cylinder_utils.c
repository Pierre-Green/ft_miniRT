/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 22:19:06 by pguthaus          #+#    #+#             */
/*   Updated: 2020/05/01 22:22:10 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "parser.h"

/*
** Base center: vec3f
** Orientation: normalized vec3f
** Diameter: float
** Height: float
** Color: color
*/

void	new_cylinder(t_cylinder *dest, t_line_result *results)
{
	dest->position = results[0].vec3f;
	dest->orientation = results[1].vec3f;
	dest->diameter = results[2].f;
	dest->height = results[3].f;
	dest->color = results[4].color;
	dest->radius = dest->diameter / 2;
}

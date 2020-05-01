/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 21:02:53 by pguthaus          #+#    #+#             */
/*   Updated: 2020/05/01 22:14:08 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "parser.h"

/*
** Center: vec3f
** Diameter: float
** Color: Color
*/

void	new_sphere(t_sphere *dest, t_line_result *results)
{
	dest->position = results[0].vec3f;
	dest->diameter = results[1].f;
	dest->color = results[2].color;
}

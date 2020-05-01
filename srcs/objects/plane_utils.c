/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 21:17:50 by pguthaus          #+#    #+#             */
/*   Updated: 2020/05/01 22:16:11 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "parser.h"

/*
** A point: vec3f
** Orientation: normalized vec3f
** Color: color
*/

void	new_plane(t_plane *dest, t_line_result *results)
{
	dest->position = results[0].vec3f;
	dest->orientation = results[1].vec3f;
	dest->color = results[2].color;
}

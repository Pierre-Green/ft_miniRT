/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 22:10:25 by pguthaus          #+#    #+#             */
/*   Updated: 2020/05/01 22:14:03 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "parser.h"

/*
** Square center: vec3f
** Orientation vector: normalized vec3f
** Side size: float
** Color: Color
*/

void	new_square(t_square *dest, t_line_result *results)
{
    dest->center = results[0].vec3f;
    dest->orientation = results[1].vec3f;
    dest->height = results[2].f;
    dest->color = results[3].color;
}

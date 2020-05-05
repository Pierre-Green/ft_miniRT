/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 22:10:25 by pguthaus          #+#    #+#             */
/*   Updated: 2020/05/05 17:23:19 by pguthaus         ###   ########.fr       */
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

static void	set_square_points(t_square *dest)
{
	t_vec3f	a;
	t_vec3f	b;
	t_vec3f	c;
	t_vec3f	d;

	a = ft_vec3f_init(dest->height / 2, dest->height / 2, 0);
	a = ft_vec3f_rot(a, dest->orientation);
	b = ft_vec3f_init(-(dest->height / 2), dest->height / 2, 0);
	b = ft_vec3f_rot(b, dest->orientation);
	c = ft_vec3f_init(dest->height / 2, -(dest->height / 2), 0);
	c = ft_vec3f_rot(c, dest->orientation);
	d = ft_vec3f_init(-(dest->height / 2), -(dest->height / 2), 0);
	d = ft_vec3f_rot(d, dest->orientation);
	dest->a = ft_vec3f_add(a, dest->center);
	dest->b = ft_vec3f_add(b, dest->center);
	dest->c = ft_vec3f_add(c, dest->center);
	dest->d = ft_vec3f_add(d, dest->center);
}

void		new_square(t_square *dest, t_line_result *results)
{
    dest->center = results[0].vec3f;
    dest->orientation = results[1].vec3f;
    dest->height = results[2].f;
    dest->color = results[3].color;
	set_square_points(dest);
	dest->ab = ft_vec3f_sub(dest->b, dest->a);
	dest->ac = ft_vec3f_sub(dest->c, dest->a);
	dest->normal = ft_vec3f_cross(dest->ab, dest->ac);
}

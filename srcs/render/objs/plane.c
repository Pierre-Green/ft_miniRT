/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 02:31:52 by pguthaus          #+#    #+#             */
/*   Updated: 2019/12/17 08:02:10 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "world.h"

/*
** Line parametric equation
*/
t_bool				plane_intersects(t_plane plane, t_vec3f origin, t_vec3f dir, float *dist)
{
	const float		t = ft_vec3f_dot(ft_vec3f_sub(plane.position, origin), plane.orientation);
	const float		denom = ft_vec3f_dot(plane.orientation, dir);

	if (denom < 1e-8)
		return (false);
	*dist = t / denom;
	return (t >= 0);
}

t_second_ray		plane_second_ray(t_plane plane, t_vec3f origin, t_vec3f dir, float dist)
{
	t_vec3f			intersection_point;

	intersection_point = ft_vec3f_add(origin, ft_vec3f_mul(dir, dist));
	return ((t_second_ray){ intersection_point, plane.orientation });
}

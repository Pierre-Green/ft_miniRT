/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 02:31:52 by pguthaus          #+#    #+#             */
/*   Updated: 2020/05/05 18:16:42 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "world.h"

/*
** Line parametric equation
*/
t_bool				plane_intersects(t_plane plane, t_vec3f origin, t_vec3f dir, float *dist)
{
	float denom;
	float calcul_a;
	float b;

	denom = -(ft_vec3f_dot(plane.orientation, plane.position));
	calcul_a = ft_vec3f_dot(origin, plane.orientation) + denom;
	b = ft_vec3f_dot(dir, plane.orientation);
	*dist = -(calcul_a / b);
	return (*dist >= 0);
}

t_second_ray		plane_second_ray(t_plane plane, t_vec3f origin, t_vec3f dir, float dist)
{
	t_vec3f			intersection_point;

	intersection_point = ft_vec3f_add(origin, ft_vec3f_mul(dir, dist));
	return ((t_second_ray){ intersection_point, ft_vec3f_mul(plane.orientation, -1) });
}

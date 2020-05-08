/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 02:31:52 by pguthaus          #+#    #+#             */
/*   Updated: 2020/05/08 17:51:22 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "world.h"

t_bool				plane_intersects(t_plane plane, t_vec3f origin, t_vec3f dir, float *dist)
{
	float denom;
	float calcul_a;
	float b;

	denom = -(v3f_dot(plane.orientation, plane.position));
	calcul_a = v3f_dot(origin, plane.orientation) + denom;
	b = v3f_dot(dir, plane.orientation);
	*dist = -(calcul_a / b);
	return (*dist >= 0);
}

t_second_ray		plane_compute_normal(t_plane plane, t_second_ray next_ray)
{
	next_ray.normal = plane.orientation;
	next_ray.has_normal_b = true;
	next_ray.normal_b = v3f_mul(plane.orientation, -1);
	return (next_ray);
}

t_bool				plane_second_ray(t_plane plane, t_second_ray *next_ray, float *dist)
{
	t_bool			does_intersect;

	does_intersect = plane_intersects(plane, next_ray->origin, next_ray->light_dir, dist);
	if (does_intersect)
		return (true);
	return (false);
}

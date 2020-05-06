/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 02:31:52 by pguthaus          #+#    #+#             */
/*   Updated: 2020/05/06 21:23:24 by pguthaus         ###   ########.fr       */
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

t_second_ray		plane_compute_normal(t_plane plane, t_second_ray next_ray)
{
	next_ray.normal = plane.orientation;
	return (next_ray);
}

t_bool				plane_second_ray(t_plane plane, t_second_ray *next_ray)
{
	t_bool			does_intersect;
	float			tmp;

	does_intersect = plane_intersects(plane, next_ray->origin, next_ray->light_dir, &tmp);
	if (does_intersect)
		return (true);
	return (false);
}

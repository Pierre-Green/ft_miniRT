/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 02:22:06 by pguthaus          #+#    #+#             */
/*   Updated: 2020/05/07 17:08:35 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "world.h"

t_bool			sphere_intersects(t_sphere sphere, t_vec3f origin, t_vec3f dir, float *dist)
{
	float		discriminant;
	float		k[2];
	float		t[2];
	t_vec3f		difference;
	float		calcul_c;

	difference = ft_vec3f_sub(origin, sphere.position);
	calcul_c = ft_vec3f_dot(difference, difference) - ((sphere.diameter / 2) * (sphere.diameter / 2));
	k[0] = ft_vec3f_dot(dir, dir);
	k[1] = 2 * ft_vec3f_dot(difference, dir);
	discriminant = k[1] * k[1] - 4 * k[0] * calcul_c;
	if (discriminant < 0)
		return (false);
	t[0] = (-k[1] + sqrt(discriminant)) / (2 * k[0]);
	t[1] = (-k[1] - sqrt(discriminant)) / (2 * k[0]);
	if (t[0] < t[1])
		*dist = t[0];
	else
		*dist = t[1];
	return (true);
}

t_second_ray		sphere_compute_normal(t_sphere sphere, t_second_ray next_ray)
{
	next_ray.normal = ft_vec3f_normalize(ft_vec3f_sub(next_ray.origin, sphere.position));
	next_ray.has_normal_b = false;
	return (next_ray);
}

t_bool				sphere_second_ray(t_sphere sphere, t_second_ray *next_ray, float *dist)
{
	t_bool			does_intersect;

	does_intersect = sphere_intersects(sphere, next_ray->origin, next_ray->light_dir, dist);
	if (does_intersect && *dist >= 0)
		return (true);
	return (false);
}

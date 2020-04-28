/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 02:22:06 by pguthaus          #+#    #+#             */
/*   Updated: 2020/04/28 16:24:34 by pguthaus         ###   ########.fr       */
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

t_second_ray		sphere_second_ray(t_sphere sphere, t_vec3f origin, t_vec3f dir, float dist)
{
	t_vec3f			intersection_point;
	t_vec3f			intersection_normal;

	intersection_point = ft_vec3f_add(origin, ft_vec3f_mul(dir, dist));
	intersection_normal = ft_vec3f_sub(sphere.position, intersection_point);
	return ((t_second_ray){ intersection_point, ft_vec3f_normalize(intersection_normal) });
}

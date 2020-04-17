/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 02:22:06 by pguthaus          #+#    #+#             */
/*   Updated: 2019/12/05 03:06:08 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "world.h"

t_bool				sphere_intersects(t_sphere sphere, t_vec3f origin, t_vec3f dir, float *dist)
{
	const t_vec3f	l = ft_vec3f_sub(sphere.position, origin);
	const float		tca = ft_vec3f_dot(l, dir);
	float			d2;
	float			thc;
	float			t0;
	float			t1;

	if (tca < 0)
		return (false);
	d2 = ft_vec3f_dot(l, l) - tca * tca;
	if (d2 > ((sphere.diameter / 2) * (sphere.diameter / 2)))
		return (false);
	thc = sqrtf(((sphere.diameter / 2) * (sphere.diameter / 2)) - d2);

	t0 = tca - thc;
	t1 = tca + thc;
	if (t0 > t1)
	{
		d2 = t0;
		t0 = t1;
		t1 = d2;
	}
	if (t0 < 0)
	{
		t0 = t1;
		if (t0 < 0)
			return (false);
	}
	*dist = t0;
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

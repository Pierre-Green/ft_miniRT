/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 02:32:54 by pguthaus          #+#    #+#             */
/*   Updated: 2020/05/08 17:51:22 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "world.h"

t_bool				cylinder_intersects(t_cylinder cylinder, t_vec3f origin, t_vec3f dir, float *dist)
{
	t_vec3f		pb;
	t_vec3f		ca;
	t_vec3f		oc;
	t_vec3f		abc;
	t_vec3f		hty;
	t_vec3f		cardoc;

	pb = v3f_add(cylinder.position, v3f_mul(cylinder.orientation, cylinder.height));
	ca = v3f_sub(pb, cylinder.position);
	oc = v3f_sub(origin, cylinder.position);

	cardoc.x = v3f_dot(ca, ca);
	cardoc.y = v3f_dot(ca, dir);
	cardoc.z = v3f_dot(ca, oc);
	abc.x = cardoc.x - (cardoc.y * cardoc.y);
	abc.y = cardoc.x * v3f_dot(oc, dir) - (cardoc.z * cardoc.y);
	abc.z = cardoc.x * v3f_dot(oc, oc) - (cardoc.z * cardoc.z)
			- (cylinder.radius * cylinder.radius * cardoc.x);
	hty.x = (abc.y * abc.y) - (abc.x * abc.z);
	if (hty.x < 0)
		return (false);
	hty.x = sqrt(hty.x);
	hty.y = (-abc.y - hty.x) / abc.x;
	hty.z = cardoc.z + (hty.y * cardoc.y);
	if (hty.z > 0 && hty.z < cardoc.x)
	{
		*dist = hty.y;
		return (true);
	}
	hty.y = (((hty.z < 0) ? 0 : cardoc.x) - cardoc.z) / cardoc.y;
	if (fabsf(abc.y + (abc.x * hty.y)) < hty.x)
	{
		*dist = hty.y;
		return (*dist > 0);
	}
	return (false);
}

t_second_ray				cylinder_compute_normal(t_cylinder cylinder, t_second_ray next_ray)
{
	t_vec3f					top_center;
	float					tmp;
	float					tmp2;

	top_center = v3f_add(cylinder.position, v3f_mul(cylinder.orientation, cylinder.height));
	if (v3f_dist(top_center, next_ray.origin) <= cylinder.radius)
		next_ray.normal = cylinder.orientation;
	else if (v3f_dist(cylinder.position, next_ray.origin) <= cylinder.radius)
		next_ray.normal = v3f_mul(cylinder.orientation, -1);
	else
	{
		tmp = v3f_len(v3f_sub(cylinder.position, next_ray.origin));
		tmp2 = sqrtf(powf(tmp, 2) - powf(cylinder.radius, 2));
		next_ray.normal = v3f_normalize(v3f_sub(next_ray.origin, v3f_add(cylinder.position, v3f_mul(cylinder.orientation, tmp2))));
	}
	next_ray.has_normal_b = false;
	return (next_ray);
}

t_bool						cylinder_second_ray(t_cylinder cylinder, t_second_ray *next_ray, float *dist)
{
	t_bool			does_intersect;

	does_intersect = cylinder_intersects(cylinder, next_ray->origin, next_ray->light_dir, dist);
	if (does_intersect)
		return (true);
	return (false);
}

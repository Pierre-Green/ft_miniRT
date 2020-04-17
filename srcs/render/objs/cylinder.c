/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 02:32:54 by pguthaus          #+#    #+#             */
/*   Updated: 2019/12/19 22:37:51 by pguthaus         ###   ########.fr       */
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

	pb = ft_vec3f_add(cylinder.position, ft_vec3f_mul(cylinder.orientation, cylinder.height));
	ca = ft_vec3f_sub(pb, cylinder.position);
	oc = ft_vec3f_sub(origin, cylinder.position);

	cardoc.x = ft_vec3f_dot(ca, ca);
	cardoc.y = ft_vec3f_dot(ca, dir);
	cardoc.z = ft_vec3f_dot(ca, oc);
	abc.x = cardoc.x - (cardoc.y * cardoc.y);
	abc.y = cardoc.x * ft_vec3f_dot(oc, dir) - (cardoc.z * cardoc.y);
	abc.z = cardoc.x * ft_vec3f_dot(oc, oc) - (cardoc.z * cardoc.z)
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

t_second_ray				cylinder_second_ray(t_cylinder cylinder, t_vec3f origin, t_vec3f dir, float dist)
{
	const t_vec3f			top = ft_vec3f_add(cylinder.position, ft_vec3f_mul(cylinder.orientation, cylinder.height));
	const t_vec3f			ca = ft_vec3f_sub(top, cylinder.position);
	const t_vec3f			oc = ft_vec3f_sub(origin, cylinder.position);
	const float				y = ft_vec3f_dot(ca, oc) + dist * ft_vec3f_dot(ca, dir);
	t_second_ray			res;

	res.hit_point = ft_vec3f_add(origin, ft_vec3f_mul(dir, dist));
	if (ft_vec3f_dist(top, res.hit_point) < cylinder.radius)
		res.ray_dir = ft_vec3f_normalize(cylinder.orientation);
	else if (ft_vec3f_dist(cylinder.position, res.hit_point) < cylinder.radius)
		res.ray_dir = ft_vec3f_normalize(ft_vec3f_mul(cylinder.orientation, -1));
	else
		res.ray_dir = ft_vec3f_normalize(ft_vec3f_mul(ft_vec3f_sub(ft_vec3f_add(oc, ft_vec3f_mul(dir, dist)), ft_vec3f_mul(ca, y)), 1 / cylinder.radius));
	return (res);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 02:33:14 by pguthaus          #+#    #+#             */
/*   Updated: 2020/05/11 15:51:27 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "world.h"

static t_bool	beetween_points(t_triangle triangle, t_vec3f origin,
	t_vec3f dir, float dist)
{
	t_vec3f		temp;
	t_vec3f		point;
	float		dot_wab_wac[2];
	t_vec3f		w;
	float		r[2];

	temp = v3f_mul(dir, dist);
	point = v3f_add(origin, temp);
	w = v3f_sub(point, triangle.a);
	dot_wab_wac[0] = v3f_dot(w, triangle.ab);
	dot_wab_wac[1] = v3f_dot(w, triangle.ac);
	r[0] = (triangle.dot_abac * dot_wab_wac[1] - triangle.dot_acac
		* dot_wab_wac[0]) / triangle.calcul_d;
	if (r[0] < 0 || r[0] > 1)
		return (false);
	r[1] = (triangle.dot_abac * dot_wab_wac[0] - triangle.dot_abab
		* dot_wab_wac[1]) / triangle.calcul_d;
	if (r[1] < 0 || (r[0] + r[1] > 1))
		return (false);
	return (true);
}

t_bool			triangle_intersects(t_triangle triangle, t_vec3f origin,
	t_vec3f dir, float *dist)
{
	float		denom;
	float		calcul_a;
	float		b;

	denom = -(v3f_dot(triangle.normal, triangle.a));
	calcul_a = v3f_dot(origin, triangle.normal) + denom;
	b = v3f_dot(dir, triangle.normal);
	*dist = -(calcul_a / b);
	if (*dist < 0)
		return (false);
	return (beetween_points(triangle, origin, dir, *dist));
}

t_second_ray	triangle_compute_normal(t_triangle triangle,
	t_second_ray next_ray)
{
	next_ray.normal = triangle.normal;
	next_ray.has_normal_b = true;
	next_ray.normal_b = v3f_mul(triangle.normal, -1);
	return (next_ray);
}

t_bool			triangle_second_ray(t_triangle triangle, t_second_ray *next_ray,
	float *dist)
{
	t_bool		does_intersect;

	does_intersect = triangle_intersects(triangle, next_ray->origin,
		next_ray->light_dir, dist);
	if (does_intersect)
		return (true);
	return (false);
}

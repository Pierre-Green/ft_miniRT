/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 02:32:27 by pguthaus          #+#    #+#             */
/*   Updated: 2020/05/08 17:51:22 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "world.h"

static t_bool		beetween_points(t_square square, t_vec3f origin, t_vec3f dir, float dist)
{
	t_vec3f		point;
	t_vec3f		temp;
	t_vec3f		ap;
	float		alpha;
	float		beta;

	temp = v3f_mul(dir, dist);
	point = v3f_add(origin, temp);
	ap = v3f_sub(point, square.a);
	alpha = v3f_dot(ap, square.ab) / v3f_dot(square.ab, square.ab);

	beta = v3f_dot(ap, square.ac) / v3f_dot(square.ac, square.ac);
	if (alpha >= 0 && alpha <= 1 && beta >= 0 && beta <= 1)
		return (true);
	return (false);
}

t_bool				square_intersects(t_square square, t_vec3f origin, t_vec3f dir, float *dist)
{
	float denom;
	float calcul_a;
	float b;

	denom = -(v3f_dot(square.normal, square.center));
	calcul_a = v3f_dot(origin, square.normal) + denom;
	b = v3f_dot(dir, square.normal);
	*dist = -(calcul_a / b);
	if (*dist < 0)
		return (false);
	return (beetween_points(square, origin, dir, *dist));
}

t_second_ray		square_compute_normal(t_square square, t_second_ray next_ray)
{
	next_ray.normal = square.normal;
	next_ray.has_normal_b = true;
	next_ray.normal_b = v3f_mul(square.normal, -1);
	return (next_ray);
}

t_bool				square_second_ray(t_square square, t_second_ray *next_ray, float *dist)
{
	t_bool			does_intersect;

	does_intersect = square_intersects(square, next_ray->origin, next_ray->light_dir, dist);
	if (does_intersect)
		return (true);
	return (false);
}

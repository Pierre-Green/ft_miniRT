/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 02:32:27 by pguthaus          #+#    #+#             */
/*   Updated: 2019/12/17 08:02:26 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "world.h"

t_bool				square_intersects(t_square square, t_vec3f origin, t_vec3f dir, float *dist)
{
	const float		t = ft_vec3f_dot(ft_vec3f_sub(square.position, origin), square.orientation);
	const float		denom = ft_vec3f_dot(square.orientation, dir);
	t_vec3f			intersection;
	t_vec3f			vec;
	t_vec3f			proj;

	if (denom < 1e-8)
		return (false);
	*dist = t / denom;
	if (t >= 0)
	{
		intersection = ft_vec3f_add(origin, ft_vec3f_mul(dir, *dist));
		vec = ft_vec3f_sub(intersection, square.position);
		proj = ft_vec3f_init(vec.x/square.height, 0, vec.z/square.height);
		return ((proj.x < square.height && proj.x > 0) &&
			(proj.z < square.height && proj.z > 0));
	}
	return (false);
}

t_second_ray		square_second_ray(t_square square, t_vec3f origin, t_vec3f dir, float dist)
{
	t_vec3f			intersection_point;

	intersection_point = ft_vec3f_add(origin, ft_vec3f_mul(dir, dist));
	return ((t_second_ray){ intersection_point, square.orientation });
}

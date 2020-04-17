/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 02:33:14 by pguthaus          #+#    #+#             */
/*   Updated: 2019/12/17 08:49:37 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "world.h"

t_bool				triangle_intersects(t_triangle triangle, t_vec3f origin, t_vec3f dir, float *dist)
{
	const float		f1 = ft_vec3f_dot(triangle.normal, dir);
	t_vec3f			intersection;

	if (fabsf(f1) < 1e-8)
		return (false);
	*dist = (ft_vec3f_dot(triangle.normal, origin) + ft_vec3f_dot(triangle.normal, triangle.point_1)) / f1;
	if (*dist < 0)
		return (false);
	intersection = ft_vec3f_add(origin, ft_vec3f_mul(dir, *dist));
	if (ft_vec3f_dot(triangle.normal, ft_vec3f_cross(ft_vec3f_sub(triangle.point_2, triangle.point_1), ft_vec3f_sub(intersection, triangle.point_1))) < 0)
		return (false);
	if (ft_vec3f_dot(triangle.normal, ft_vec3f_cross(ft_vec3f_sub(triangle.point_3, triangle.point_2), ft_vec3f_sub(intersection, triangle.point_2))) < 0)
		return (false);
	if (ft_vec3f_dot(triangle.normal, ft_vec3f_cross(ft_vec3f_sub(triangle.point_1, triangle.point_3), ft_vec3f_sub(intersection, triangle.point_3))) < 0)
		return (false);
	return (true);
}

t_second_ray		triangle_second_ray(t_triangle triangle, t_vec3f origin, t_vec3f dir, float dist)
{
	t_vec3f			intersection_point;

	intersection_point = ft_vec3f_add(origin, ft_vec3f_mul(dir, dist));
	return ((t_second_ray){ intersection_point, triangle.normal });
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 02:33:14 by pguthaus          #+#    #+#             */
/*   Updated: 2020/05/01 21:23:02 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "world.h"

t_bool				triangle_intersects(t_triangle triangle, t_vec3f origin, t_vec3f dir, float *dist)
{
	float denom;
	float calcul_a;
	float b;

	denom = -(ft_vec3f_dot(triangle.normal, triangle.a));
	calcul_a = ft_vec3f_dot(origin, triangle.normal) + denom;
	b = ft_vec3f_dot(dir, triangle.normal);
	*dist = -(calcul_a / b);
	if (*dist < 0)
		return (false);
	return (true);
}

t_second_ray		triangle_second_ray(t_triangle triangle, t_vec3f origin, t_vec3f dir, float dist)
{
	t_vec3f			intersection_point;

	intersection_point = ft_vec3f_add(origin, ft_vec3f_mul(dir, dist));
	return ((t_second_ray){ intersection_point, triangle.normal });
}

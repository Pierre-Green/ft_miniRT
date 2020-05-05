/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 02:32:27 by pguthaus          #+#    #+#             */
/*   Updated: 2020/05/05 17:27:29 by pguthaus         ###   ########.fr       */
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

	temp = ft_vec3f_mul(dir, dist);
	point = ft_vec3f_add(origin, temp);
	ap = ft_vec3f_sub(point, square.a);
	alpha = ft_vec3f_dot(ap, square.ab) / ft_vec3f_dot(square.ab, square.ab);

	beta = ft_vec3f_dot(ap, square.ac) / ft_vec3f_dot(square.ac, square.ac);
	if (alpha >= 0 && alpha <= 1 && beta >= 0 && beta <= 1)
		return (true);
	return (false);
}

t_bool				square_intersects(t_square square, t_vec3f origin, t_vec3f dir, float *dist)
{
	float denom;
	float calcul_a;
	float b;

	denom = -(ft_vec3f_dot(square.normal, square.center));
	calcul_a = ft_vec3f_dot(origin, square.normal) + denom;
	b = ft_vec3f_dot(dir, square.normal);
	*dist = -(calcul_a / b);
	if (*dist < 0)
		return (false);
	return (beetween_points(square, origin, dir, *dist));
}

t_second_ray		square_second_ray(t_square square, t_vec3f origin, t_vec3f dir, float dist)
{
	t_vec3f			intersection_point;

	intersection_point = ft_vec3f_add(origin, ft_vec3f_mul(dir, dist));
	return ((t_second_ray){ intersection_point, square.orientation });
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 02:32:27 by pguthaus          #+#    #+#             */
/*   Updated: 2020/05/01 22:23:30 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "world.h"

t_bool				square_intersects(t_square square, t_vec3f origin, t_vec3f dir, float *dist)
{
	(void)square;
	(void)origin;
	(void)dir;
	(void)dist;
	return (false);
}

t_second_ray		square_second_ray(t_square square, t_vec3f origin, t_vec3f dir, float dist)
{
	t_vec3f			intersection_point;

	intersection_point = ft_vec3f_add(origin, ft_vec3f_mul(dir, dist));
	return ((t_second_ray){ intersection_point, square.orientation });
}

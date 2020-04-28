/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 17:23:56 by pguthaus          #+#    #+#             */
/*   Updated: 2020/04/28 21:16:09 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_bool		intersects(t_obj *obj, t_vec3f origin, t_vec3f dir, float *dist)
{
	if (obj->type == SPHERE)
		return (sphere_intersects(obj->obj.sphere, origin, dir, dist));
	if (obj->type == PLANE)
		return (plane_intersects(obj->obj.plane, origin, dir, dist));
	if (obj->type == SQUARE)
		return (square_intersects(obj->obj.square, origin, dir, dist));
	if (obj->type == CYLINDER)
		return (cylinder_intersects(obj->obj.cylinder, origin, dir, dist));
	if (obj->type == TRIANGLE)
		return (triangle_intersects(obj->obj.triangle, origin, dir, dist));
	return (false);
}

t_second_ray			get_next_ray(t_obj *hitted, t_vec3f origin, t_vec3f raydir, float dist)
{
	if (hitted->type == SPHERE)
		return (sphere_second_ray(hitted->obj.sphere, origin, raydir, dist));
	if (hitted->type == PLANE)
		return (plane_second_ray(hitted->obj.plane, origin, raydir, dist));
	if (hitted->type == SQUARE)
		return (square_second_ray(hitted->obj.square, origin, raydir, dist));
	if (hitted->type == CYLINDER)
		return (cylinder_second_ray(hitted->obj.cylinder, origin, raydir, dist));
	if (hitted->type == TRIANGLE)
		return (triangle_second_ray(hitted->obj.triangle, origin, raydir, dist));
	return ((t_second_ray){ ft_vec3f_init1(0), ft_vec3f_init1(0) });
}

t_color				get_hitted_color(t_obj *hitted)
{
	if (hitted->type == SPHERE)
		return (hitted->obj.sphere.color);
	if (hitted->type == PLANE)
		return (hitted->obj.plane.color);
	if (hitted->type == SQUARE)
		return (hitted->obj.square.color);
	if (hitted->type == CYLINDER)
		return (hitted->obj.cylinder.color);
	if (hitted->type == TRIANGLE)
		return (hitted->obj.triangle.color);
	return (0);
}

t_color				trace(t_vec3f origin, t_vec3f raydir, t_carry *c)
{
	t_obj			*hitted;
	float			nearest;
	float			distance;
	unsigned int	i;
	t_second_ray	next_ray;

	hitted = 0;
	nearest = FLT_MAX;
	i = 0;
	while (i < c->w->objs_count)
	{
		distance = FLT_MAX;
		if (intersects(c->w->objs[i], origin, raydir, &distance))
		{
			if (distance > 1e-4 && distance < nearest)
			{
				hitted = c->w->objs[i];
				nearest = distance;
				break ;
			}
		}
		i++;
	}
	if (!hitted)
		return (ft_color_rgb(0, 0, 0));
	next_ray = get_next_ray(hitted, origin, raydir, nearest);

	// Check for any lights
	uint8_t			transmission;
	t_vec3f			light_direction;
	t_color			color;
	unsigned int	k;
	unsigned int	j;
	float			light_power;

	// Apply ambiant light
	color = get_hitted_color(hitted);
	color = ft_color_set_r(color, ft_color_get_r(color) * (ft_color_get_r(c->w->ambiant_light->color) / 255.0f) * c->w->ambiant_light->ratio);
	color = ft_color_set_g(color, ft_color_get_g(color) * (ft_color_get_g(c->w->ambiant_light->color) / 255.0f) * c->w->ambiant_light->ratio);
	color = ft_color_set_b(color, ft_color_get_b(color) * (ft_color_get_b(c->w->ambiant_light->color) / 255.0f) * c->w->ambiant_light->ratio);
	
	k = 0;
	while (k < c->w->lights_count)
	{
		transmission = 1;
		light_direction = ft_vec3f_normalize(ft_vec3f_sub(c->w->lights[k]->position, next_ray.hit_point));
		j = 0;
		while (j < c->w->objs_count)
		{
			if (j != i)
			{
				if (intersects(c->w->objs[j], ft_vec3f_add(next_ray.hit_point, ft_vec3f_mul(next_ray.ray_dir, 1e-4)), light_direction, &distance))
				{
					transmission = 0;
					break ;
				}
			}
			j++;
		}

		// Apply light
		if (transmission)
		{
			light_power = ft_vec3f_dot(next_ray.ray_dir, light_direction);
			if (light_power > 0)
			{
				color = ft_color_set_r(color, ft_min(255, ft_color_get_r(color) + (light_power * ft_color_get_r(c->w->lights[k]->color))));
				color = ft_color_set_g(color, ft_min(255, ft_color_get_g(color) + (light_power * ft_color_get_g(c->w->lights[k]->color))));
				color = ft_color_set_b(color, ft_min(255, ft_color_get_b(color) + (light_power * ft_color_get_b(c->w->lights[k]->color))));	
			}
		}
		k++;
	}
	return (color);
}

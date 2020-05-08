/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting_shadowing.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 17:29:27 by pguthaus          #+#    #+#             */
/*   Updated: 2020/05/08 18:01:01 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_bool		intersects(t_obj *obj, t_second_ray *next_ray,
	t_light *light)
{
	t_bool			result;
	float			distance;

	if (obj->type == SPHERE)
		result = sphere_second_ray(obj->obj.sphere, next_ray, &distance);
	if (obj->type == PLANE)
		result = plane_second_ray(obj->obj.plane, next_ray, &distance);
	if (obj->type == SQUARE)
		result = square_second_ray(obj->obj.square, next_ray, &distance);
	if (obj->type == CYLINDER)
		result = cylinder_second_ray(obj->obj.cylinder, next_ray, &distance);
	if (obj->type == TRIANGLE)
		result = triangle_second_ray(obj->obj.triangle, next_ray, &distance);
	if (!result)
		return (false);
	if (distance >= v3f_len(v3f_sub(light->position,
			next_ray->origin)))
		return (false);
	return (true);
}

static t_second_ray	compute_normal(t_second_ray next_ray)
{
	if (next_ray.hitted->type == SPHERE)
		return (sphere_compute_normal(next_ray.hitted->obj.sphere,
		next_ray));
	else if (next_ray.hitted->type == PLANE)
		return (plane_compute_normal(next_ray.hitted->obj.plane,
		next_ray));
	else if (next_ray.hitted->type == SQUARE)
		return (square_compute_normal(next_ray.hitted->obj.square,
		next_ray));
	else if (next_ray.hitted->type == CYLINDER)
		return (cylinder_compute_normal(next_ray.hitted->obj.cylinder,
		next_ray));
	else if (next_ray.hitted->type == TRIANGLE)
		return (triangle_compute_normal(next_ray.hitted->obj.triangle,
		next_ray));
	else
		return (next_ray);
}

static t_second_ray	apply_light(t_second_ray next_ray, t_light *light)
{
	float			light_powers[2];
	int				i;

	light_powers[0] = v3f_dot(next_ray.normal, next_ray.light_dir);
	light_powers[1] = v3f_dot(next_ray.normal_b, next_ray.light_dir);
	i = -1;
	while (++i < 2)
	{
		if (i == 1 && !next_ray.has_normal_b)
			break ;
		if (light_powers[i] > 0)
		{
			next_ray.light_fac.x = ft_fmin(1.0f, next_ray.light_fac.x
				+ (light_powers[i] * ((ft_color_get_r(light->color) / 255.0f)
				* light->ratio)));
			next_ray.light_fac.y = ft_fmin(1.0f, next_ray.light_fac.y
				+ (light_powers[i] * ((ft_color_get_g(light->color) / 255.0f)
				* light->ratio)));
			next_ray.light_fac.z = ft_fmin(1.0f, next_ray.light_fac.z
				+ (light_powers[i] * ((ft_color_get_b(light->color) / 255.0f)
				* light->ratio)));
		}
	}
	return (next_ray);
}

static t_second_ray	lights(t_second_ray next_ray, t_carry *c)
{
	unsigned int	i;
	unsigned int	j;
	t_bool			transmission;

	i = 0;
	while (i < c->w->lights_count)
	{
		next_ray.light_dir = v3f_normalize(v3f_sub(c->w->lights[i]->position,
			next_ray.origin));
		transmission = true;
		j = 0;
		while (j < c->w->objs_count)
		{
			if (c->w->objs[j] != next_ray.hitted && intersects(c->w->objs[j],
				&next_ray, c->w->lights[i]))
			{
				transmission = false;
				break ;
			}
			j++;
		}
		if (transmission)
			next_ray = apply_light(next_ray, c->w->lights[i]);
		i++;
	}
	return (next_ray);
}

t_color				process_light_and_shadow(t_second_ray next_ray, t_carry *c)
{
	next_ray.light_fac = v3f_init(
		(ft_color_get_r(c->w->ambiant_light->color) / 255.0f)
			* c->w->ambiant_light->ratio,
		(ft_color_get_g(c->w->ambiant_light->color) / 255.0f)
			* c->w->ambiant_light->ratio,
		(ft_color_get_b(c->w->ambiant_light->color) / 255.0f)
			* c->w->ambiant_light->ratio);
	next_ray = compute_normal(next_ray);
	next_ray = lights(next_ray, c);
	next_ray.color = ft_color_set_r(next_ray.color,
		ft_color_get_r(next_ray.color) * next_ray.light_fac.x);
	next_ray.color = ft_color_set_g(next_ray.color,
		ft_color_get_g(next_ray.color) * next_ray.light_fac.y);
	next_ray.color = ft_color_set_b(next_ray.color,
		ft_color_get_b(next_ray.color) * next_ray.light_fac.z);
	return (next_ray.color);
}

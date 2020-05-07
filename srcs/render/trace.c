/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 17:23:56 by pguthaus          #+#    #+#             */
/*   Updated: 2020/05/07 17:25:31 by pguthaus         ###   ########.fr       */
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

static t_color		get_hitted_color(t_obj *hitted)
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

static t_obj		*get_closest_obj(t_vec3f origin, t_vec3f raydir, t_carry *c, float *distance)
{
	t_obj			*hitted;
	float			nearest;
	unsigned int	i;

	hitted = 0;
	nearest = FLT_MAX;
	i = 0;
	while (i < c->w->objs_count)
	{
		*distance = FLT_MAX;
		if (intersects(c->w->objs[i], origin, raydir, distance))
		{
			if (*distance < nearest)
			{
				hitted = c->w->objs[i];
				nearest = *distance;
			}
		}
		i++;
	}
	*distance = nearest;
	return (hitted);
}


t_color				trace(t_vec3f origin, t_vec3f raydir, t_carry *c)
{
	t_obj			*hitted;
	float			distance;
	t_second_ray	next_ray;

	if (!(hitted = get_closest_obj(origin, raydir, c, &distance)))
		return (ft_color_rgb(0, 0, 0));
	next_ray.hitted = hitted;
	next_ray.color = get_hitted_color(hitted);
	next_ray.distance = distance;
	next_ray.origin = ft_vec3f_add(origin, ft_vec3f_mul(raydir, distance));
	return (process_light_and_shadow(next_ray, c));
}

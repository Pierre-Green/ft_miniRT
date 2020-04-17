/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 19:21:23 by pguthaus          #+#    #+#             */
/*   Updated: 2020/01/06 19:42:38 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WORLD_H
# define WORLD_H
# include <stdint.h>
# include "libft.h"

typedef struct		s_second_ray
{
	t_vec3f			hit_point;
	t_vec3f			ray_dir;
}					t_second_ray;


typedef struct		s_light
{
	t_vec3f			position;
	double			dry_wet;
	t_color			color;
}					t_light;
typedef struct		s_ambiant_light
{
	float			ratio;
	t_color			color;
}					t_ambiant_light;
typedef struct		s_camera
{
	t_vec3f			position;
	t_vec3f			forward;
	t_vec3f			right;
	t_vec3f			up;
}					t_camera;
/*
** Objects
*/
typedef struct		s_sphere
{
	t_vec3f			position;
	double			diameter;
	t_color			color;
}					t_sphere;
t_bool				sphere_intersects(t_sphere sphere, t_vec3f origin, t_vec3f dir, float *dist);
t_second_ray		sphere_second_ray(t_sphere sphere, t_vec3f origin, t_vec3f dir, float dist);
typedef struct		s_plane
{
	t_vec3f			position;
	t_vec3f			orientation;
	t_color			color;
}					t_plane;
t_bool				plane_intersects(t_plane plane, t_vec3f origin, t_vec3f dir, float *dist);
t_second_ray		plane_second_ray(t_plane plane, t_vec3f origin, t_vec3f dir, float dist);
typedef struct		s_square
{
	t_vec3f			position;
	t_vec3f			orientation;
	double			height;
	t_color			color;
}					t_square;
t_bool				square_intersects(t_square square, t_vec3f origin, t_vec3f dir, float *dist);
t_second_ray		square_second_ray(t_square square, t_vec3f origin, t_vec3f dir, float dist);
typedef struct		s_cylinder
{
	t_vec3f			position;
	t_vec3f			orientation;
	double			diameter;
	double			radius;
	double			height;
	t_color			color;
}					t_cylinder;
t_bool				cylinder_intersects(t_cylinder cylinder, t_vec3f origin, t_vec3f dir, float *dist);
t_second_ray		cylinder_second_ray(t_cylinder cylinder, t_vec3f origin, t_vec3f dir, float dist);
typedef struct		s_triangle
{
	t_vec3f			point_1;
	t_vec3f			point_2;
	t_vec3f			point_3;
	t_vec3f			normal;
	t_color			color;
}					t_triangle;
t_bool				triangle_intersects(t_triangle triangle, t_vec3f origin, t_vec3f dir, float *dist);
t_second_ray		triangle_second_ray(t_triangle triangle, t_vec3f origin, t_vec3f dir, float dist);
typedef enum		e_obj_types
{
	SPHERE,
	PLANE,
	SQUARE,
	CYLINDER,
	TRIANGLE
}					t_obj_types;
typedef struct		s_obj
{
	t_obj_types		type;
	union			u_objs
	{
		t_sphere	sphere;
		t_plane		plane;
		t_square	square;
		t_cylinder	cylinder;
		t_triangle	triangle;
	}				obj;
}					t_obj;
typedef struct		s_world
{
	uint16_t		res[2];
	t_ambiant_light	*ambiant_light;
	t_camera		**cameras;
	size_t			cameras_count;
	t_light			**lights;
	size_t			lights_count;
	t_obj			**objs;
	size_t			objs_count;
}					t_world;

#endif

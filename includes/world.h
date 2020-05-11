/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 16:04:43 by pguthaus          #+#    #+#             */
/*   Updated: 2020/05/11 16:04:44 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WORLD_H
# define WORLD_H
# include <stdint.h>
# include "libft.h"

typedef struct		s_second_ray
{
	struct s_obj	*hitted;
	t_color			color;
	float			distance;
	t_vec3f			origin;
	t_vec3f			light_fac;
	t_vec3f			normal;
	t_bool			has_normal_b;
	t_vec3f			normal_b;
	t_vec3f			light_dir;
}					t_second_ray;

typedef struct		s_light
{
	t_vec3f			position;
	float			ratio;
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
	t_vec3f			rotation;
	t_vec3f			forward;
	t_vec3f			right;
	t_vec3f			up;
	int				fov;
}					t_camera;
void				set_camera_axes(t_camera *cam);
/*
** Objects
*/
typedef struct		s_sphere
{
	t_vec3f			position;
	double			diameter;
	t_color			color;
}					t_sphere;
t_bool				sphere_intersects(t_sphere sphere, t_vec3f origin,
	t_vec3f dir, float *dist);
t_second_ray		sphere_compute_normal(t_sphere sphere,
	t_second_ray next_ray);
t_bool				sphere_second_ray(t_sphere sphere, t_second_ray *next_ray,
	float *dist);
typedef struct		s_plane
{
	t_vec3f			position;
	t_vec3f			orientation;
	t_color			color;
}					t_plane;
t_bool				plane_intersects(t_plane plane, t_vec3f origin, t_vec3f dir,
	float *dist);
t_second_ray		plane_compute_normal(t_plane plane, t_second_ray next_ray);
t_bool				plane_second_ray(t_plane plane, t_second_ray *next_ray,
	float *dist);
typedef struct		s_square
{
	t_vec3f			center;
	t_vec3f			orientation;
	double			height;
	t_vec3f			a;
	t_vec3f			b;
	t_vec3f			c;
	t_vec3f			d;
	t_vec3f			ab;
	t_vec3f			ac;
	t_vec3f			normal;
	t_color			color;
}					t_square;
t_bool				square_intersects(t_square square, t_vec3f origin,
	t_vec3f dir, float *dist);
t_second_ray		square_compute_normal(t_square square,
	t_second_ray next_ray);
t_bool				square_second_ray(t_square square, t_second_ray *next_ray,
	float *dist);
typedef struct		s_cylinder
{
	t_vec3f			position;
	t_vec3f			orientation;
	double			diameter;
	double			radius;
	double			height;
	t_color			color;
}					t_cylinder;
t_bool				cylinder_intersects(t_cylinder cylinder, t_vec3f origin,
	t_vec3f dir, float *dist);
t_second_ray		cylinder_compute_normal(t_cylinder cylinder,
	t_second_ray next_ray);
t_bool				cylinder_second_ray(t_cylinder cylinder,
	t_second_ray *next_ray, float *dist);
typedef struct		s_triangle
{
	t_vec3f			a;
	t_vec3f			b;
	t_vec3f			c;
	t_vec3f			ab;
	t_vec3f			ac;
	float			dot_abab;
	float			dot_abac;
	float			dot_acac;
	float			calcul_d;
	t_vec3f			normal;
	t_color			color;
}					t_triangle;
t_bool				triangle_intersects(t_triangle triangle, t_vec3f origin,
	t_vec3f dir, float *dist);
t_second_ray		triangle_compute_normal(t_triangle triangle,
	t_second_ray next_ray);
t_bool				triangle_second_ray(t_triangle triangle,
	t_second_ray *next_ray, float *dist);
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
	unsigned int	res[2];
	t_ambiant_light	*ambiant_light;
	t_camera		**cameras;
	size_t			cameras_count;
	t_light			**lights;
	size_t			lights_count;
	t_obj			**objs;
	size_t			objs_count;
}					t_world;

#endif

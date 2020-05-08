/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 04:23:58 by pguthaus          #+#    #+#             */
/*   Updated: 2020/04/17 22:24:37 by pguthaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void			set_pixel(unsigned int pos, t_color color, t_carry *c)
{
	c->s->image[pos] = ft_color_get_b(color);
	c->s->image[pos + 1] = ft_color_get_g(color);
	c->s->image[pos + 2] = ft_color_get_r(color);
}

static t_vec3f		to_world(t_vec3f v, t_camera *cam)
{
	float			mat[4][4];

	mat[0][0] = cam->right.x;
    mat[0][1] = cam->right.y;
    mat[0][2] = cam->right.z;
    mat[1][0] = cam->up.x;
    mat[1][1] = cam->up.y;
    mat[1][2] = cam->up.z;
    mat[2][0] = cam->forward.x;
    mat[2][1] = cam->forward.y;
    mat[2][2] = cam->forward.z;

	return v3f_init(
		v.x * mat[0][0] + v.y * mat[1][0] + v.z * mat[2][0],
		v.x * mat[0][1] + v.y * mat[1][1] + v.z * mat[2][1],
		v.x * mat[0][2] + v.y * mat[1][2] + v.z * mat[2][2]
	);
}

static t_vec3f		get_raydir(int x, int y, t_carry *c)
{
	t_camera		*camera;
	t_vec3f			dir;
	float			scale;
	float			aspect_ratio;

	camera = c->w->cameras[c->s->cam];
	scale = tanf(fdeg2rad(camera->fov * 0.5));
	aspect_ratio = c->w->res[0] / (float)c->w->res[1];
	dir = v3f_init(
		(2 * (x + 0.5) / (float)c->w->res[0] - 1) * aspect_ratio * scale,
		(1 - 2 * (y + 0.5) / (float)c->w->res[1]) * scale,
		1);
	dir = to_world(dir, camera);
	return (v3f_normalize(dir));
}

void				render(t_carry *c)
{
	unsigned int	x;
	unsigned int	y;
	unsigned int	pos;
	t_color			pixel;
	t_vec3f			origin;

	origin = c->w->cameras[c->s->cam]->position;
	y = 0;
	while (y < c->w->res[1])
	{
		x = 0;
		while (x < c->w->res[0])
		{
			pixel = trace(to_world(origin, c->w->cameras[c->s->cam]), get_raydir(x, y, c), c);
			pos = (((y * c->s->size_line) + (x * (c->s->bits_per_pixel / 8))));
			set_pixel(pos, pixel, c);
			x++;
		}
		y++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 04:23:58 by pguthaus          #+#    #+#             */
/*   Updated: 2020/04/17 18:33:47 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void			set_pixel(unsigned int pos, t_color color, t_carry *c)
{
	c->s->image[pos] = ft_color_get_b(color);
	c->s->image[pos + 1] = ft_color_get_g(color);
	c->s->image[pos + 2] = ft_color_get_r(color);
}

t_vec3f				c2w(t_vec3f vec, t_carry *c)
{
	t_vec3f			res;
	float			c2w[4][4];
	const t_camera	*camera = c->w->cameras[c->s->cam];

	c2w[0][0] = camera->right.x;
	c2w[0][1] = camera->right.y;
	c2w[0][2] = camera->right.z;
	c2w[1][0] = camera->up.x;
	c2w[1][1] = camera->up.y;
	c2w[1][2] = camera->up.z;
	c2w[2][0] = camera->forward.x;
	c2w[2][1] = camera->forward.y;
	c2w[2][2] = camera->forward.z;

	res.x = vec.x * c2w[0][0] + vec.y * c2w[1][0] + vec.z * c2w[2][0];
	res.y = vec.x * c2w[0][1] + vec.y * c2w[1][1] + vec.z * c2w[2][1];
	res.z = vec.x * c2w[0][2] + vec.y * c2w[1][2] + vec.z * c2w[2][2];
	return (res);
}

static t_vec3f		get_raydir(unsigned int x, unsigned int y, t_carry *c)
{
	t_vec3f			vec;
	float			scale;
	float			aspect_ratio;

	scale = tanf(M_PI * 0.5 * 70 / 180);
	aspect_ratio = c->w->res[0] / (float) c->w->res[1];
	vec = c2w(ft_vec3f_init((	2 * (x + 0.5) / (float)c->w->res[0] - 1) * scale * aspect_ratio,
							(1 - 2 * (y + 0.5) / (float)c->w->res[1]) * scale,
							1), c);
	return (ft_vec3f_normalize(vec));
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
			pixel = trace(origin, get_raydir(x, y, c), c);
			pos = (((y * c->s->size_line) + (x * (c->s->bits_per_pixel / 8))));
			set_pixel(pos, pixel, c);
			x++;
		}
		y++;
	}
}

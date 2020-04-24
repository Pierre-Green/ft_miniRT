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

// TODO FIX IT
static t_vec3f		get_raydir(int x, int y, t_carry *c)
{
	t_vec3f			vec;
	float			width;
	float			height;
	float			scale;

	x = -(c->w->res[0] / 2) + 1 + x;
	y = -(c->w->res[1] / 2) + 1 + y;

	width = 1;
	height = 1;
	if (c->w->res[0] >= c->w->res[1])
		width = (float)c->w->res[0] / c->w->res[1];
	else
		height = (float)c->w->res[1] / c->w->res[0];

	scale = tanf(M_PI * 0.5 * c->w->cameras[c->s->cam]->fov / 180);

	vec = ft_vec3f_init(
		x * (width / c->w->res[0]) * scale,
		y * (height / c->w->res[1]) * scale,
		1
	);

	return (ft_vec3f_rot(vec, c->w->cameras[c->s->cam]->forward));
	/*
	float			scale;
	float			aspect_ratio;

	scale = tanf(M_PI * 0.5 * 70 / 180);
	aspect_ratio = c->w->res[0] / (float) c->w->res[1];
	vec = c2w(ft_vec3f_init((	2 * (x + 0.5) / (float)c->w->res[0] - 1) * scale * aspect_ratio,
							(1 - 2 * (y + 0.5) / (float)c->w->res[1]) * scale,
							1), c);
	return (ft_vec3f_normalize(vec));
	*/
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 03:12:31 by pguthaus          #+#    #+#             */
/*   Updated: 2020/05/08 17:51:22 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void				move(int key, t_carry *c)
{
	t_camera			*cam;

	cam = c->w->cameras[c->s->cam];
	if (key == KEY_W)
		cam->position = v3f_add(cam->position, v3f_mul(cam->forward, VELOCITY_MOVE));
	else if (key == KEY_S)
		cam->position = v3f_add(cam->position, v3f_mul(cam->forward, -1 * VELOCITY_MOVE));
	else if (key == KEY_A)
		cam->position = v3f_add(cam->position, v3f_mul(cam->right, -1 * VELOCITY_MOVE));
	else if (key == KEY_D)
		cam->position = v3f_add(cam->position, v3f_mul(cam->right, VELOCITY_MOVE));
	else if (key == KEY_R)
		cam->position = v3f_add(cam->position, v3f_init(0, VELOCITY_MOVE, 0));
	else if (key == KEY_F)
		cam->position = v3f_add(cam->position, v3f_init(0, -1 * VELOCITY_MOVE, 0));
}

static void				rotate(int key, t_carry *c)
{
	t_camera			*cam;

	cam = c->w->cameras[c->s->cam];
	if (key == KEY_ARROW_DOWN)
		cam->rotation.x -= VELOCITY_ROTATE;
	if (key == KEY_ARROW_UP)
		cam->rotation.x += VELOCITY_ROTATE;
	if (key == KEY_ARROW_LEFT)
		cam->rotation.y -= VELOCITY_ROTATE;
	if (key == KEY_ARROW_RIGHT)
		cam->rotation.y += VELOCITY_ROTATE;
	set_camera_axes(cam);
}

static void				next_cam(t_carry *c)
{
	if (c->s->cam == c->w->cameras_count - 1)
		c->s->cam = 0;
	else
		c->s->cam++;
}

static int					on_key_pressed(int key, void *p_c)
{
	const t_carry		*c = (t_carry *)p_c;

	if (key == KEY_ESC)
	{
		freexit(0, 0, (t_carry *)c);
		return (0);
	}
	if (key == KEY_W || key == KEY_A || key == KEY_S || key == KEY_D || key == KEY_R || key == KEY_F)
		move(key, (t_carry *)c);
	else if (key == KEY_ARROW_DOWN || key == KEY_ARROW_LEFT || key == KEY_ARROW_RIGHT || key == KEY_ARROW_UP)
		rotate(key, (t_carry *)c);
	else if (key == KEY_C)
		next_cam((t_carry *)c);
	else
		return -1;
	render((t_carry *)c);
	do_output((t_carry *)c);
	return (0);
}

static int				on_window_closed(void *p_c)
{
	freexit(0, 0, (t_carry *)p_c);
	return (0);
}

void					init_window(t_carry *c)
{
	if (!(c->s->mlx_ptr = mlx_init()))
		freexit(20, "Failed to mlx_init()", c);
	if (!(c->s->win_ptr = mlx_new_window(c->s->mlx_ptr, c->w->res[0], c->w->res[1], "MiniRT")))
		freexit(21, "Failed to mlx_new_window()", c);
	if (!(c->s->img_ptr = mlx_new_image(c->s->mlx_ptr, c->w->res[0], c->w->res[1])))
		freexit(22, "Failed to mlx_new_image()", c);
	c->s->image = mlx_get_data_addr(c->s->img_ptr, &(c->s->bits_per_pixel), &(c->s->size_line), &(c->s->endian));
	mlx_hook(c->s->win_ptr, 2, 1L << 0, on_key_pressed, c);
	mlx_hook(c->s->win_ptr, 17, 1L << 17, on_window_closed, c);
}

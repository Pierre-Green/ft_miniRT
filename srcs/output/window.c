/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 03:12:31 by pguthaus          #+#    #+#             */
/*   Updated: 2020/04/18 01:37:49 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#define POSITION_VEL 0.5
#define ORIENTATION_VEL 0.1

static void				move(int key, t_carry *c)
{
	t_camera			*cam;

	cam = c->w->cameras[c->s->cam];
	if (key == KEY_W)
		cam->position = ft_vec3f_add(cam->position, ft_vec3f_mul(cam->forward, POSITION_VEL));
	else if (key == KEY_A)
		cam->position = ft_vec3f_sub(cam->position, ft_vec3f_mul(cam->right, POSITION_VEL));
	else if (key == KEY_S)
		cam->position = ft_vec3f_sub(cam->position, ft_vec3f_mul(cam->forward, POSITION_VEL));
	else if (key == KEY_D)
		cam->position = ft_vec3f_add(cam->position, ft_vec3f_mul(cam->right, POSITION_VEL));
}

static void				rotate(int key, t_carry *c)
{
	t_camera			*cam;

	cam = c->w->cameras[c->s->cam];
	if (key == KEY_ARROW_DOWN)
		cam->forward = ft_vec3f_sub(cam->forward, ft_vec3f_init(0, ORIENTATION_VEL, 0));
	if (key == KEY_ARROW_UP)
		cam->forward = ft_vec3f_add(cam->forward, ft_vec3f_init(0, ORIENTATION_VEL, 0));
	if (key == KEY_ARROW_LEFT)
		cam->forward = ft_vec3f_sub(cam->forward, ft_vec3f_init(0, 0, ORIENTATION_VEL));
	if (key == KEY_ARROW_RIGHT)
		cam->forward = ft_vec3f_add(cam->forward, ft_vec3f_init(0, 0, ORIENTATION_VEL));
	cam->right = ft_vec3f_cross(cam->forward, ft_vec3f_init(0, 1, 0));
	cam->up = ft_vec3f_cross(cam->forward, cam->right);
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

	ft_printf("Key pressed: %d\n", key);
	if (key == KEY_ESC)
	{
		mlx_destroy_image(c->s->mlx_ptr, c->s->img_ptr);
		mlx_destroy_window(c->s->mlx_ptr, c->s->win_ptr);
		exit(0);
	}
	if (key == KEY_W || key == KEY_A || key == KEY_S || key == KEY_D)
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

void					init_window(t_carry *c)
{
	if (!(c->s->mlx_ptr = mlx_init()))
		freexit(20, "Failed to mlx_init()", c);
	if (!(c->s->win_ptr = mlx_new_window(c->s->mlx_ptr, c->w->res[0], c->w->res[1], "MiniRT")))
		freexit(21, "Failed to mlx_new_window()", c);
	if (!(c->s->img_ptr = mlx_new_image(c->s->mlx_ptr, c->w->res[0], c->w->res[1])))
		freexit(22, "Failed to mlx_new_image()", c);
	c->s->image = mlx_get_data_addr(c->s->img_ptr, &(c->s->bits_per_pixel), &(c->s->size_line), &(c->s->endian));
	mlx_key_hook(c->s->win_ptr, on_key_pressed, c);
}

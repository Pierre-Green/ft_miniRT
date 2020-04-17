/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 17:52:08 by pguthaus          #+#    #+#             */
/*   Updated: 2020/04/17 18:34:56 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void			init_world(t_carry *c)
{
	t_world			*world;

	if (!(world = malloc(sizeof(t_world))))
		freexit(-42, "Allocation error", c);
	world->res[0] = 0;
	world->res[1] = 0;
	world->ambiant_light = 0;
	world->cameras = 0;
	world->cameras_count = 0;
	world->lights = 0;
	world->lights_count = 0;
	world->objs = 0;
	world->objs_count = 0;
	c->w = world;
}

static void			init_state(t_carry *c)
{
	t_state			*state;

	if (!(state = malloc(sizeof(t_state))))
		freexit(-42, "Allocation error", c);
	state->cam = 0;
	state->image = 0;
	state->savemode = false;
	state->mlx_ptr = 0;
	state->win_ptr = 0;
	state->img_ptr = 0;
	state->bits_per_pixel = 42;
	state->size_line = 0;
	c->s = state;
}

static void			create_buffer(t_carry *c)
{
	if (!(c->s->image = malloc(sizeof(uint8_t)
			* (3 * c->w->res[0] * c->w->res[1]))))
		freexit(-42, "Allocation failed", c);
	c->s->bits_per_pixel = sizeof(uint8_t) * 8 * 3;
	c->s->size_line = c->w->res[0] * 8;
}

static void			validate_args(const t_args *args, char **filename,
	t_bool *savemode)
{
	t_bool			error;

	error = false;
	*savemode = false;
	if (args->count == 0 || args->count > 2)
		error = true;
	if (args->count == 1)
		*filename = args->args[0];
	if (args->count == 2)
	{
		if (ft_strncmp(args->args[0], "-save", 5)
			&& ft_strncmp(args->args[1], "-save", 5))
			error = true;
		*savemode = true;
		if (ft_strncmp(args->args[0], "-save", 5))
			*filename = args->args[0];
		else
			*filename = args->args[1];
	}
	if (error)
	{
		ft_printf("%s\n", USAGE);
		exit(-5);
	}
}

int					main(int argc, char **argv)
{
	t_args			*args;
	char			*file_name;
	t_carry			*c;

	if (!(args = ft_args_start(argc, argv)))
		freexit(-42, "Args parsing error", 0);
	if (!(c = malloc(sizeof(t_carry))))
		freexit(-42, "Allocation error", 0);
	init_state(c);
	init_world(c);
	validate_args(args, &file_name, &(c->s->savemode));
	load_world(file_name, c);
	if (!c->s->savemode)
		init_window(c);
	else
		create_buffer(c);
	render(c);
	do_output(c);
	ft_args_end(&args);
	freexit(0, 0, c);
}

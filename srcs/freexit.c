/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freexit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 19:29:08 by pguthaus          #+#    #+#             */
/*   Updated: 2020/04/17 18:28:49 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <stdio.h>

static void			free_world(t_world *world)
{
	unsigned int	i;

	i =  0;
	if (world->ambiant_light)
		free((void *)world->ambiant_light);
	while (i < world->cameras_count)
		free((void *)world->cameras[i++]);
	free((void *)world->cameras);
	i = 0;
	while (i < world->lights_count)
		free((void *)world->lights[i++]);
	free((void *)world->lights);
	i = 0;
	while (i < world->objs_count)
		free((void *)world->objs[i++]);
	free((void *)world->objs);
	free((void *)world);
}

static void			free_state(t_state *state)
{
	mlx_destroy_image(state->mlx_ptr, state->img_ptr);
	mlx_destroy_window(state->mlx_ptr, state->win_ptr);
}

void				freexit(int exit_code, const char *message, t_carry *c)
{
	if (message)
		perror(message);
	free_world(c->w);
	free_state(c->s);
	free((void *)c);
	exit(exit_code);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 06:44:58 by pguthaus          #+#    #+#             */
/*   Updated: 2020/01/06 19:35:58 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "minirt.h"

void					parse_camera(char *line, t_carry *c)
{
	const t_line_spec	specs[3] = { VEC3F, NVEC3F, NONE };
	t_line_result		*results;
	t_camera			*cams[c->w->cameras_count];
	unsigned int		i;

	results = parse_line_specs(line, (t_line_spec *)specs, 1, c);
	i = 0;
	while (i < c->w->cameras_count && (cams[i] = c->w->cameras[i]))
		i++;
	free(c->w->cameras);
	if (!(c->w->cameras = malloc(sizeof(t_camera *) * i)))
		freexit(-42, "Allocation failed", c);
	i = 0;
	while (i < c->w->cameras_count && (c->w->cameras[i] = cams[i]))
		i++;
	if (!(c->w->cameras[i] = malloc(sizeof(t_camera))))
		freexit(-42, "Allocation failed", c);
	c->w->cameras[i]->position = results[0].vec3f;
	c->w->cameras[i]->forward = results[1].vec3f;
	c->w->cameras[i]->right = ft_vec3f_cross(results[1].vec3f, ft_vec3f_init(0, 1, 0));
	c->w->cameras[i]->up = ft_vec3f_cross(results[1].vec3f, c->w->cameras[i]->right);
	c->w->cameras_count++;
}

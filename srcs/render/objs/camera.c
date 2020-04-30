/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 16:01:59 by pguthaus          #+#    #+#             */
/*   Updated: 2020/04/30 22:07:28 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void				set_camera_axes(t_camera *cam)
{
	t_vec3f			angles;

	angles = ft_vec3f_mul(cam->rotation, 360);
	angles = ft_vec3f_init(
		angles.x / 180 * M_PI,
		angles.y / 180 * M_PI,
		angles.z / 180 * M_PI
	);
	cam->forward = ft_vec3f_rot(ft_vec3f_init(0, 0, 1), angles);
	cam->right = ft_vec3f_rot(ft_vec3f_init(1, 0, 0), angles);
	cam->up = ft_vec3f_rot(ft_vec3f_init(0, 1, 0), angles);
}
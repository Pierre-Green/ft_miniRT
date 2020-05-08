/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 16:01:59 by pguthaus          #+#    #+#             */
/*   Updated: 2020/05/08 17:51:22 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void				set_camera_axes(t_camera *cam)
{
	cam->forward = v3f_rot(v3f_init(0, 0, 1), cam->rotation);
	cam->right = v3f_cross(v3f_init(0, 1, 0), cam->forward);
	cam->up = v3f_cross(cam->forward, cam->right);
}

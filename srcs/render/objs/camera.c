/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 16:01:59 by pguthaus          #+#    #+#             */
/*   Updated: 2020/05/05 17:38:32 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void				set_camera_axes(t_camera *cam)
{
	cam->forward = ft_vec3f_rot(ft_vec3f_init(0, 0, 1), cam->rotation);
	cam->right = ft_vec3f_rot(ft_vec3f_init(1, 0, 0), cam->rotation);
	cam->up = ft_vec3f_rot(ft_vec3f_init(0, 1, 0), cam->rotation);
}

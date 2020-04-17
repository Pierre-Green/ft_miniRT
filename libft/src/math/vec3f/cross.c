/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cross.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 19:01:27 by pguthaus          #+#    #+#             */
/*   Updated: 2019/11/25 19:13:16 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_vec3f				ft_vec3f_cross(t_vec3f vec1, t_vec3f vec2)
{
	return ((t_vec3f){	vec1.y * vec2.z - vec1.z * vec2.y,
						vec1.z * vec2.x - vec1.x * vec2.z,
						vec1.x * vec2.y - vec1.y * vec2.x});
}

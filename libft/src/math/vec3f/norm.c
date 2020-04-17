/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 19:01:42 by pguthaus          #+#    #+#             */
/*   Updated: 2019/11/25 19:21:56 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

float				ft_vec3f_norm(t_vec3f vec)
{
	return (vec.x * vec.x + vec.y * vec.y + vec.z * vec.z);
}

t_vec3f				ft_vec3f_normalize(t_vec3f vec)
{
	const float		n = ft_vec3f_norm(vec);
	float			fac;

	if (n > 0)
	{
		fac = 1 / sqrtf(n);
		vec.x *= fac;
		vec.y *= fac;
		vec.z *= fac;
	}
	return (vec);
}

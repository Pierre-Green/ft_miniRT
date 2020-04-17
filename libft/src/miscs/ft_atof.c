/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 22:10:40 by pguthaus          #+#    #+#             */
/*   Updated: 2019/11/29 05:09:42 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

float				ft_atof(const char *str)
{
	float			result;
	float			fac;
	t_bool			point_seen;

	result = 0;
	fac = 1;
	point_seen = false;
	if (*str == '-' && *str++)
		fac = -1;
	while (*str)
	{
		if (*str == '.')
			point_seen = true;
		else if (*str - '0' >= 0 && *str - '0' <= 9)
		{
			if (point_seen)
				fac /= 10.0f;
			result = result * 10.0f + (float)*str - '0';
		}
		else
			break ;
		str++;
	}
	return (result * fac);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 04:29:05 by pguthaus          #+#    #+#             */
/*   Updated: 2019/11/29 04:50:07 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

uint8_t				ft_color_get_r(t_color color)
{
	return ((color >> 24) & 0xff);
}

uint8_t				ft_color_get_g(t_color color)
{
	return ((color >> 16) & 0xff);
}

uint8_t				ft_color_get_b(t_color color)
{
	return ((color >> 8) & 0xff);
}

uint8_t				ft_color_get_a(t_color color)
{
	return (color & 0xff);
}

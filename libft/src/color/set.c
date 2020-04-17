/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 04:28:41 by pguthaus          #+#    #+#             */
/*   Updated: 2019/11/29 05:08:26 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_color				ft_color_set_r(t_color color, uint8_t r)
{
	return (ft_color_rgba(r, ft_color_get_g(color),
		ft_color_get_b(color), ft_color_get_a(color)));
}

t_color				ft_color_set_g(t_color color, uint8_t g)
{
	return (ft_color_rgba(ft_color_get_r(color), g,
		ft_color_get_b(color), ft_color_get_a(color)));
}

t_color				ft_color_set_b(t_color color, uint8_t b)
{
	return (ft_color_rgba(ft_color_get_r(color),
		ft_color_get_g(color), b, ft_color_get_a(color)));
}

t_color				ft_color_set_a(t_color color, uint8_t a)
{
	return (ft_color_rgba(ft_color_get_r(color),
		ft_color_get_g(color), ft_color_get_b(color), a));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 19:26:16 by pguthaus          #+#    #+#             */
/*   Updated: 2019/11/29 07:32:51 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_color				ft_color_rgba(uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
	return (((r & 0xff) << 24) + ((g & 0xff) << 16)
		+ ((b & 0xff) << 8) + (a & 0xff));
}

t_color				ft_color_rgb(uint8_t r, uint8_t g, uint8_t b)
{
	return (ft_color_rgba(r, g, b, 1));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 15:39:15 by pguthaus          #+#    #+#             */
/*   Updated: 2020/05/11 17:00:56 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void				do_output(t_carry *c)
{
	if (!c->s->savemode)
	{
		mlx_put_image_to_window(c->s->mlx_ptr, c->s->win_ptr, c->s->img_ptr,
			0, 0);
		mlx_loop(c->s->mlx_ptr);
	}
	else
		write_bpm_file(c);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 03:30:23 by pguthaus          #+#    #+#             */
/*   Updated: 2020/01/07 16:45:29 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STATE_H
# define STATE_H
# include "libft.h"

typedef struct	s_state
{
	uint16_t	cam;
	char		*image;
	t_bool		savemode;
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	int			bits_per_pixel;
	int			size_line;
	int			endian;
}				t_state;

#endif

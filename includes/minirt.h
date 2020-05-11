/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 17:30:13 by pguthaus          #+#    #+#             */
/*   Updated: 2020/05/11 15:42:51 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H
# include "world.h"
# include "state.h"
# include "mlx.h"
# include <float.h>
# include <math.h>
# define USAGE "Usage: ./minirt [-save] file"
# define V_MOVE 1
# define VELOCITY_ROTATE 0.02

typedef struct		s_carry
{
	t_world			*w;
	t_state			*s;
}					t_carry;

void				load_world(const char *file, t_carry *c);
void				init_window(t_carry *c);
void				render(t_carry *c);
t_color				trace(t_vec3f origin, t_vec3f raydir, t_carry *c);
t_color				process_light_and_shadow(t_second_ray next_ray, t_carry *c);
void				do_output(t_carry *c);

void				freexit(int exit_code, const char *message, t_carry *c);

#endif

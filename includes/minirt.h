/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 19:29:27 by pguthaus          #+#    #+#             */
/*   Updated: 2020/04/17 18:33:37 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H
# include "world.h"
# include "state.h"
# include <mlx.h>
# include <float.h>
# include <math.h>
# define USAGE "Usage: ./minirt [-save] file"
#ifndef M_PI
  #define M_PI 3.14159265358979323846
#endif 

typedef struct		s_carry
{
	t_world			*w;
	t_state			*s;
}					t_carry;

void				load_world(const char *file, t_carry *c);
void				init_window(t_carry *c);
void				render(t_carry *c);
t_color				trace(t_vec3f origin, t_vec3f raydir, t_carry *c);
t_vec3f				c2w(t_vec3f vec, t_carry *c);
void				do_output(t_carry *c);

void				freexit(int exit_code, const char *message, t_carry *c);

#endif

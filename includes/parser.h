/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 19:43:10 by pguthaus          #+#    #+#             */
/*   Updated: 2020/05/01 22:19:46 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H
# include "world.h"
# include "minirt.h"
# define SPEC_MAX 5

typedef enum		e_line_spec
{
	NONE = 0,
	INT = 1,
	FLOAT = 2,
	COLOR = 3,
	VEC3F = 4,
	NVEC3F = 5
}					t_line_spec;

typedef union		u_line_result
{
	int				i;
	float			f;
	t_color			color;
	t_vec3f			vec3f;
}					t_line_result;

t_line_result		*parse_line_specs(char *line, t_line_spec *specs,
	unsigned int pos, t_carry *c);
void				add_obj(t_obj *obj, t_carry *c);
void				parse_error(char *line, unsigned int pos,
	const char *message, t_carry *c);

void				parse_resolution(char *line, t_carry *c);
void				parse_light(char *line, t_carry *c);
void				parse_ambiant_light(char *line, t_carry *c);
void				parse_camera(char *line, t_carry *c);

void				parse_sphere(char *line, t_carry *c);
void				new_sphere(t_sphere *dest, t_line_result *results);
void				parse_plane(char *line, t_carry *c);
void				new_plane(t_plane *dest, t_line_result *results);
void				parse_square(char *line, t_carry *c);
void				new_square(t_square *dest, t_line_result *results);
void				parse_cylinder(char *line, t_carry *c);
void				new_cylinder(t_cylinder *dest, t_line_result *results);
void				parse_triangle(char *line, t_carry *c);
void				new_triangle(t_triangle *dest, t_line_result *results);

#endif

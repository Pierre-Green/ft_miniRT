/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 00:44:34 by pguthaus          #+#    #+#             */
/*   Updated: 2020/01/06 19:32:30 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "parser.h"

static char		tab_to_space(unsigned int i, char c)
{
	(void)i;
	if (c == '\t')
		return (' ');
	return (c);
}

void			parse_error(char *line, unsigned int pos, const char *message, t_carry *c)
{
	ft_printf("\nError in line: '%s'\n", ft_strmapi(line, tab_to_space));
	ft_printf("%*s %s\n", pos + 16, "↑", message);
	freexit(-1, 0, c);
}

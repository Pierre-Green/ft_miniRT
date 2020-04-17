/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assert.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 16:07:22 by pguthaus          #+#    #+#             */
/*   Updated: 2019/10/17 15:21:41 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

void			printf_assert(char const *name, char const *format, ...)
{
	va_list		args;
	int			ret1;
	int			ret2;

	va_start(args, format);
	printf("Starting `%s`:\n", name);
	ft_printf("Mine: ");
	ret1 = ft_printf_va(format, args);
	printf("\n");
	va_end(args);
	va_start(args, format);
	printf("FBSD: ");
	ret2 = vprintf(format, args);
	printf("\n|%d VS %d|\n\n", ret1, ret2);
	va_end(args);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 16:17:42 by pguthaus          #+#    #+#             */
/*   Updated: 2019/10/29 15:22:35 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

void	test_fmt_int(void)
{
	printf_assert("Int fmt 1:", "|%d|", 42);
	printf_assert("Int fmt 2:", "|%d|", -42);
	printf_assert("Int fmt 3:", "|%.-1d|", 42);
	printf_assert("Int fmt 4:", "|%05d|", 42);
	printf_assert("Int fmt 5:", "|%-5d|", 42);
	printf_assert("Int fmt 6:", "|%d|", INT_MIN);
	printf_assert("Int fmt 7:", "|%15d|", INT_MIN);
	printf_assert("Int fmt 8:", "|%-15d|", INT_MIN);
	printf_assert("Int fmt 9:", "|%.15d|", INT_MIN);
	printf_assert("Int fmt 10:", "|%015d|", INT_MIN);
	printf_assert("Int fmt 11:", "|%d|", NULL);
	printf_assert("Int fmt 12:", "|%d|", UINT64_MAX);
	printf_assert("Int fmt 13:", "|%.0d|", UINT64_MAX);
	printf_assert("Int fmt 14:", "|%.0d|", 1);
	printf_assert("Int fmt 15:", "|%10.0d|", 0);
	printf_assert("Int fmt 16:", "|%.0d|", 42);
	printf_assert("Int fmt 17:", "|%.-5d|", 42);
	printf_assert("Int fmt 18:", "|%.5d|", 42);
	printf_assert("Int fmt 19:", "|%0-15.-5d|", -561321);
	printf_assert("Int fmt 20:", "|%*d|", 15, 4224516);
	printf_assert("Int fmt 21:", "|%.*d|", 10, 4224516);
}

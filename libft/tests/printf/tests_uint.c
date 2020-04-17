/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_uint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 16:17:42 by pguthaus          #+#    #+#             */
/*   Updated: 2019/10/29 12:17:23 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

void	test_fmt_uint(void)
{
	printf_assert("uint fmt 1:", "|%u|", 42);
	printf_assert("uint fmt 2:", "|%.10u|", 42);
	printf_assert("uint fmt 3:", "|%010u|", 42);
	printf_assert("uint fmt 4:", "|%-10u|", 42);
	printf_assert("uint fmt 5:", "|%10u|", 42);
	printf_assert("uint fmt 6:", "|%15u|", UINT_MAX);
	printf_assert("uint fmt 7:", "|%.0u|", 42);
	printf_assert("uint fmt 8:", "|%.0u|", 0);
	printf_assert("uint fmt 9:", "|%.1u|", 0);
	printf_assert("uint fmt 10:", "|%10.0u|", 1);
	printf_assert("uint fmt 11:", "|%.-5u|", 11651);
	printf_assert("uint fmt 12:", "|%15.-5u|", 42214221);
	printf_assert("uint fmt 13:", "|%-15.5u|", 42214221);
	printf_assert("uint fmt 14:", "|%0-15.5u|", 42214221);
}

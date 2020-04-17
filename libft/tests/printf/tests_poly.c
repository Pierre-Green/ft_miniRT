/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_poly.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 19:01:22 by pguthaus          #+#    #+#             */
/*   Updated: 2019/11/29 05:10:48 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

void		test_fmt_poly(void)
{
	printf_assert("Test poly 1", "|%d: %s; %c|", INT_MIN,
		"j'aime le cacao", 'z');
	printf_assert("Test poly 2", "|%5d: %-23s; %5c|", INT_MIN,
		"j'aime le cacao", 'z');
	printf_assert("Test poly 3", "|%s %d %u %x %p|", "abracadabra",
		-24654523, 4242424242, 42, (void *)&"de");
	printf_assert("Test poly 4", "|%015.-5s %015d %.5u %x %p|", "abracadabra",
		-24654523, 4242424242, 42, (void *)&"de");
	printf_assert("Test poly 5", "|%015.5s %-15d %.-5u %X %p|", "abracadabra",
		-24654523, 4242424242, 42, (void *)&"de");
	printf_assert("Test poly 6", "|%*.*d %*s %3X|", 5, 3, 23, 2, "caca", 42);
}

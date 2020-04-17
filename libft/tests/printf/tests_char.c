/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 16:16:13 by pguthaus          #+#    #+#             */
/*   Updated: 2019/10/29 12:54:38 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

void	test_fmt_char(void)
{
	printf_assert("Char fmt 1", "|%5c|", 'c');
	printf_assert("Char fmt 2", "|%-5c|", 'c');
	printf_assert("Char fmt 3", "|%-05c|", 'c');
	printf_assert("Char fmt 4", "|%0-5c|", 'c');
	printf_assert("Char fmt 5", "|%05c|", 'c');
	printf_assert("Char fmt 6", "|%00c|", 'c');
	printf_assert("Char fmt 7", "|%00c|", '\0');
	printf_assert("Char fmt 8", "|%00c|", "44");
	printf_assert("Char fmt 9", "|%00c|", NULL);
	printf_assert("Char fmt 10", "|%.0c|", 'a');
	printf_assert("Char fmt 11", "|%.-5c|", 'x');
	printf_assert("Char fmt 12", "|%0-15.-5c|", 'x');
}

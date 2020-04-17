/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 16:16:58 by pguthaus          #+#    #+#             */
/*   Updated: 2019/10/29 14:48:07 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

void		test_fmt_ptr(void)
{
	char	*ptr;

	if ((ptr = malloc(sizeof(char) * 10)) == NULL)
		return ;
	printf_assert("Ptr fmt 1", "|%p|", ptr);
	printf_assert("Ptr fmt 2", "|%20p|", ptr);
	printf_assert("Ptr fmt 3", "|%-20p|", ptr);
	printf_assert("Ptr fmt 4", "|%020p|", ptr);
	printf_assert("Ptr fmt 5", "|%.20p|", ptr);
	printf_assert("Ptr fmt 6", "|%-.20p|", ptr);
	printf_assert("Ptr fmt 7", "|%p|", NULL);
	printf_assert("Ptr fmt 8", "|%10p|", NULL);
	printf_assert("Ptr fmt 9", "|%.10p|", NULL);
	printf_assert("Ptr fmt 10", "|%.1p|", NULL);
	printf_assert("Ptr fmt 11", "|%.0p|", NULL);
	printf_assert("Ptr fmt 12", "|%.-15p|", ptr);
	printf_assert("Ptr fmt 13", "|%15p|", ptr);
	printf_assert("Ptr fmt 14", "|%-0.-15p|", ptr);
	printf_assert("Ptr fmt 14", "|%.-25p|", ptr);
	free(ptr);
}

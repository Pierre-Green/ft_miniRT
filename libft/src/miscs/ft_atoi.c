/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 12:28:49 by pguthaus          #+#    #+#             */
/*   Updated: 2020/04/17 17:19:58 by pguthaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdio.h>

static int		process(const char *str)
{
	int			result;

	result = 0;
	while (*str)
	{
		if (ft_isdigit(*str))
		{
			result *= 10;
			result += *str - '0';
			str++;
		}
		else
			break ;
	}
	return (result);
}

int				ft_atoi(const char *str)
{
	char		fac;
	const char	*trimmed = ft_strtrim(str, " \n\t\v\f\r");

	if (!trimmed)
		return (0);
	fac = 1;
	if (*trimmed == '-' || *trimmed == '+')
	{
		if (*trimmed == '-')
			fac = -1;
		trimmed++;
	}
	return (fac * process(trimmed));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_args_start.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 19:03:58 by pguthaus          #+#    #+#             */
/*   Updated: 2019/11/26 19:55:44 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_args		*get_args(int argc)
{
	t_args			*result;

	if (!(result = malloc(sizeof(t_args))))
		return (NULL);
	if (!(result->args = malloc(sizeof(char *) * argc)))
		return (NULL);
	result->args[argc] = 0;
	result->count = argc - 1;
	return (result);
}

t_args				*ft_args_start(int argc, char **argv)
{
	t_args			*args;
	size_t			i;

	if (!(args = get_args(argc)))
		return (NULL);
	i = 0;
	while (i < (size_t)argc - 1)
	{
		args->args[i] = argv[i + 1];
		i++;
	}
	return (args);
}

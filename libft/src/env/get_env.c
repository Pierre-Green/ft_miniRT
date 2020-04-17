/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 22:04:17 by pguthaus          #+#    #+#             */
/*   Updated: 2020/03/05 22:19:19 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char			*extract_value(char *env)
{
	unsigned int	i;

	i = 0;
	while (env[i] && env[i] != '=')
		i++;
	if (env[i] == '=')
		i++;
	return (env + i);
}

char				*get_env(const char *key, char **env)
{
	unsigned int	i;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp(key, env[i], ft_strlen(key)) == 0)
			return (extract_value(env[i]));
		i++;
	}
	return (NULL);
}

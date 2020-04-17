/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 15:38:59 by pguthaus          #+#    #+#             */
/*   Updated: 2019/10/17 14:19:20 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_chr(char const *s, char c)
{
	const char	*ptr = s;
	size_t		count;

	count = 0;
	if (s[0] && s[0] != c)
		count++;
	while (*ptr)
	{
		if (*ptr == c && *(ptr + 1) && *(ptr + 1) != c)
			count++;
		ptr++;
	}
	return (count);
}

static char		*next(char *str, char **arr, char c)
{
	size_t		len;
	char		*part;

	while (*str && *str == c)
		str++;
	len = 0;
	while (str[len] && str[len] != c)
		len++;
	if (!*str)
		return ("");
	if ((part = ft_calloc(len + 1, sizeof(char))) == NULL)
		return (NULL);
	ft_memccpy(part, str, 0, len);
	*arr = part;
	return (str + len);
}

static char		**clear(char **result)
{
	char		**node;
	char		**tmp;

	node = result;
	while (node)
	{
		tmp = node;
		node++;
		free((void *)*tmp);
		*tmp = NULL;
	}
	free(result);
	result = NULL;
	return (result);
}

char			**ft_split(char const *s, char c)
{
	char		**result;
	char		**arr_ptr;
	char		*str_ptr;

	if (!s)
		return (NULL);
	if ((result = ft_calloc(count_chr(s, c) + 1, sizeof(char *))) == NULL)
		return (NULL);
	arr_ptr = result;
	str_ptr = (char *)s;
	while (*str_ptr)
	{
		if ((str_ptr = next(str_ptr, arr_ptr, c)) == NULL)
			return (clear(result));
		if (!*str_ptr)
			break ;
		str_ptr++;
		arr_ptr++;
	}
	return (result);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flush.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 15:36:01 by pguthaus          #+#    #+#             */
/*   Updated: 2019/11/26 00:54:24 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf/buff.h"

void				buff_flush(t_buff *buff)
{
	write(1, buff->buff, buff->len);
	buff->len = 0;
}

void				buff_flush_if_full(t_buff *buff)
{
	if (buff->len == BUFF_SIZE)
		buff_flush(buff);
}

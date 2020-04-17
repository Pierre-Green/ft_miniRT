/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buff.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 15:27:17 by pguthaus          #+#    #+#             */
/*   Updated: 2019/10/17 15:24:49 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUFF_H
# define BUFF_H
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"
# define BUFF_SIZE 32

typedef struct		s_buff
{
	char			buff[BUFF_SIZE];
	size_t			len;
}					t_buff;

size_t				buff_write_uchar(t_buff *buff, unsigned char c);

size_t				buff_write_nchar(t_buff *buff, size_t count,
	unsigned char c);

size_t				buff_write_strl(t_buff *buff, char *s, size_t len);

size_t				buff_write_str(t_buff *buff, char *s);

size_t				buff_write_int(t_buff *buff, int n);

size_t				buff_write_uint(t_buff *buff, unsigned int n);

size_t				buff_write_hex(t_buff *buff, unsigned long int n,
	char uppercase);

void				buff_flush_if_full(t_buff *buff);

void				buff_flush(t_buff *buff);

#endif

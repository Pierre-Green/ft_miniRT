/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 16:10:51 by pguthaus          #+#    #+#             */
/*   Updated: 2020/05/11 17:26:48 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <fcntl.h>

static void			write_header(char **value, t_carry *c, const int size)
{
	*(unsigned short *)*value = *(const unsigned int *)(unsigned long)"BM";
	*(unsigned int *)(*value + 2) = (size + BMP_HEADER);
	*(unsigned int *)(*value + 6) = 0u;
	*(unsigned char *)(*value + 10) = BMP_HEADER;
	*(unsigned int *)(*value + 14) = BMP_HEADER - 14;
	*(unsigned int *)(*value + 18) = c->w->res[0];
	*(unsigned int *)(*value + 22) = c->w->res[1];
	*(unsigned short *)(*value + 26) = 1;
	*(unsigned short *)(*value + 28) = 24;
	*(unsigned int *)(*value + 30) = 0;
	*(unsigned int *)(*value + 34) = (unsigned int)size;
	*(unsigned int *)(*value + 38) = 3780;
	*(unsigned int *)(*value + 42) = 3780;
	*(int *)(*value + 46) = 0;
	*(int *)(*value + 50) = 0;
}

static void			write_image(char **value, t_carry *c)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	x;
	unsigned int	y;

	i = BMP_HEADER;
	y = 0;
	while (y < c->w->res[1])
	{
		x = 0;
		while (x < c->w->res[0])
		{
			j = (x * (c->s->bits_per_pixel / 8))
				+ ((c->w->res[1] - y) * c->s->size_line);
			*(*value + i++) = *(c->s->image + j++);
			*(*value + i++) = *(c->s->image + j++);
			*(*value + i++) = *(c->s->image + j);
			x++;
		}
		y++;
	}
}

void				write_bpm_file(t_carry *c)
{
	int				fd;
	char			*value;
	const int		image_size = c->w->res[0] * c->w->res[1] * 3;
	int				tmp;

	if ((fd = open("output.bmp", O_CREAT | O_TRUNC | O_RDWR, 0644)) <= 0)
		freexit(-9, "Error while opening ouput file", c);
	if (!(value = malloc(sizeof(char) * (image_size + BMP_HEADER))))
		freexit(-42, "Malloc error", c);
	tmp = 0;
	while (tmp < BMP_HEADER)
	{
		value[tmp] = 0;
		tmp++;
	}
	write_header(&value, c, image_size);
	write_image(&value, c);
	if (write(fd, value, image_size + BMP_HEADER) != image_size + BMP_HEADER)
	{
		free((void *)value);
		freexit(-33, "Failed to write to bmp file", c);
	}
	free((void *)value);
	close(fd);
}

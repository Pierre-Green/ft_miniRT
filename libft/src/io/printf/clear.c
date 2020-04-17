/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 15:51:36 by pguthaus          #+#    #+#             */
/*   Updated: 2019/11/26 00:57:46 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf/state.h"

void		clear_state(t_state *state)
{
	if (state->buff)
		free((void *)state->buff);
	state->buff = NULL;
	state->frmt = NULL;
	free((void *)state);
}

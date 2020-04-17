/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_keys.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 03:46:17 by pguthaus          #+#    #+#             */
/*   Updated: 2020/04/18 00:11:30 by pguthaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_KEYS_H
# ifdef __APPLE__
#  define KEY_ESC 53
#  define KEY_W 13
#  define KEY_A 0
#  define KEY_S 1
#  define KEY_D 2
#  define KEY_C 8
#  define KEY_ARROW_LEFT 123
#  define KEY_ARROW_UP 126
#  define KEY_ARROW_RIGHT 124
#  define KEY_ARROW_DOWN 125
#  define KEY_PAD_0 82
#  define KEY_PAD_DOT 65
#  define KEY_PAD_8 91
#  define KEY_PAD_6 88
#  define KEY_PAD_2 84
#  define KEY_PAD_4 86
# elif __linux__
#  define KEY_ESC 65307
#  define KEY_W 122
#  define KEY_A 113
#  define KEY_S 115
#  define KEY_D 100
#  define KEY_C 99
#  define KEY_ARROW_LEFT 65361
#  define KEY_ARROW_UP 65362
#  define KEY_ARROW_RIGHT 65363
#  define KEY_ARROW_DOWN 65364
#  define KEY_PAD_0 82
#  define KEY_PAD_DOT 65
#  define KEY_PAD_8 91
#  define KEY_PAD_6 88
#  define KEY_PAD_2 84
#  define KEY_PAD_4 86
# endif

#endif

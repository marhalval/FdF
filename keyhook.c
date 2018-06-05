/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvashchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/13 16:29:43 by hvashchu          #+#    #+#             */
/*   Updated: 2017/09/13 16:29:45 by hvashchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	key_zoom(int keycode, t_win *new)
{
	if (keycode == 24)
		scale(1.1, new->map, new);
	if (keycode == 27)
		scale(0.9, new->map, new);
}

void	key_rotation(int keycode, t_win *new)
{
	if (keycode == 12)
		rotation_x(10 * ANGLE, new->map, new);
	if (keycode == 13)
		rotation_x(-10 * ANGLE, new->map, new);
	if (keycode == 0)
		rotation_y(10 * ANGLE, new->map, new);
	if (keycode == 1)
		rotation_y(-10 * ANGLE, new->map, new);
	if (keycode == 6)
		rotation_z(10 * ANGLE, new->map, new);
	if (keycode == 7)
		rotation_z(-10 * ANGLE, new->map, new);
}

void	key_translation(int keycode, t_win *new)
{
	if (keycode == 123)
		translation(-15, new->map, 'x', new);
	if (keycode == 124)
		translation(15, new->map, 'x', new);
	if (keycode == 125)
		translation(15, new->map, 'y', new);
	if (keycode == 126)
		translation(-15, new->map, 'y', new);
}

int		keyhook(int keycode, t_win *new)
{
	if (keycode == 53)
		exit(0);
	key_zoom(keycode, new);
	key_rotation(keycode, new);
	key_translation(keycode, new);
	redraw(new, new->map);
	return (0);
}

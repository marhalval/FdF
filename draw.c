/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvashchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/08 14:28:22 by hvashchu          #+#    #+#             */
/*   Updated: 2017/09/08 14:28:26 by hvashchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		valid_pixel(t_pixel p)
{
	if (p.x >= 0 && p.x <= WIDTH && p.y >= 0 && p.y <= HEIGHT)
		return (1);
	return (0);
}

void	put_pixel(t_pixel pix, t_win *win)
{
	if (valid_pixel(pix) == 1)
	{
		win->line[(int)(pix.y) * win->size + (int)(pix.x) * 4] = pix.rgb[2];
		win->line[(int)(pix.y) * win->size + (int)(pix.x) * 4 + 1] = pix.rgb[1];
		win->line[(int)(pix.y) * win->size + (int)(pix.x) * 4 + 2] = pix.rgb[0];
	}
}

void	gradient(t_pixel *p, t_pixel start, t_line line)
{
	p->rgb[0] = start.rgb[0] + (line.rgb_step[0] * (line.n - line.length));
	p->rgb[1] = start.rgb[1] + (line.rgb_step[1] * (line.n - line.length));
	p->rgb[2] = start.rgb[2] + (line.rgb_step[2] * (line.n - line.length));
}

void	draw1(t_pixel p, t_line line, t_win *win, int way)
{
	t_pixel	tmp;
	int		d;

	tmp = p;
	d = (way == 1) ? -line.dx : -line.dy;
	line.length++;
	while (line.length--)
	{
		if (line.length != line.n)
			gradient(&tmp, p, line);
		put_pixel(tmp, win);
		if (way == 1)
			tmp.x += line.sx;
		else
			tmp.y += line.sy;
		d += (way == 1) ? 2 * line.dy : 2 * line.dx;
		if (d > 0)
		{
			d -= (way == 1) ? 2 * line.dx : 2 * line.dy;
			if (way == 1)
				tmp.y += line.sy;
			else
				tmp.x += line.sx;
		}
	}
}

void	draw_line(t_pixel p1, t_pixel p2, t_win *win)
{
	t_line	line;

	line.dx = fabs(p1.x - p2.x);
	line.dy = fabs(p1.y - p2.y);
	line.sx = (p2.x - p1.x >= 0) ? 1 : -1;
	line.sy = (p2.y - p1.y >= 0) ? 1 : -1;
	line.length = fmax(line.dx, line.dy);
	line.n = line.length;
	if (line.length != 0)
	{
		line.rgb_step[0] = (p2.rgb[0] - p1.rgb[0]) / (double)line.length;
		line.rgb_step[1] = (p2.rgb[1] - p1.rgb[1]) / (double)line.length;
		line.rgb_step[2] = (p2.rgb[2] - p1.rgb[2]) / (double)line.length;
	}
	if (line.dy <= line.dx)
		draw1(p1, line, win, 1);
	else
		draw1(p1, line, win, 0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_win.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvashchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/11 15:47:26 by hvashchu          #+#    #+#             */
/*   Updated: 2017/08/11 15:49:26 by hvashchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_win(t_win *new)
{
	new->mlx = mlx_init();
	new->win = mlx_new_window(new->mlx, WIDTH, HEIGHT, "fdf");
}

void	adapt(t_win *win, t_map *map)
{
	double	zoom;
	t_pixel	offset;

	offset.x = (WIDTH - map->width) * 0.5;
	offset.y = (HEIGHT - map->height) * 0.5;
	translation(offset.x, map, 'x', win);
	translation(offset.y, map, 'y', win);
	zoom = (double)WIDTH / 4 / (double)win->map->width;
	find_center(win);
	scale(zoom, win->map, win);
	redraw(win, map);
}

void	redraw(t_win *new, t_map *map)
{
	new->img = mlx_new_image(new->mlx, WIDTH, HEIGHT);
	new->line = mlx_get_data_addr(new->img, &new->bpp, &new->size, &new->endi);
	find_center(new);
	if (map->width == 1 && map->height == 1)
		put_pixel(map->pixel[0][0], new);
	else
		draw_map(map, new);
	mlx_put_image_to_window(new->mlx, new->win, new->img, 0, 0);
	mlx_destroy_image(new->mlx, new->img);
}

void	find_center(t_win *new)
{
	int h;
	int w;

	h = new->map->height - 1;
	w = new->map->width - 1;
	new->center.x = (new->map->pixel[0][0].x + new->map->pixel[h][w].x) / 2;
	new->center.y = (new->map->pixel[0][0].y + new->map->pixel[h][w].y) / 2;
}

void	draw_map(t_map *map, t_win *new)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width - 1)
		{
			draw_line(map->pixel[i][j], map->pixel[i][j + 1], new);
			j++;
		}
		i++;
	}
	i = 0;
	while (i < map->width)
	{
		j = 0;
		while (j < map->height - 1)
		{
			draw_line(map->pixel[j][i], map->pixel[j + 1][i], new);
			j++;
		}
		i++;
	}
}

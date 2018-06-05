/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvashchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/13 19:59:34 by hvashchu          #+#    #+#             */
/*   Updated: 2017/09/13 19:59:37 by hvashchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	scale(double scale, t_map *map, t_win *new)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			map->pixel[i][j].x -= new->center.x;
			map->pixel[i][j].y -= new->center.y;
			map->pixel[i][j].x *= scale;
			map->pixel[i][j].y *= scale;
			map->pixel[i][j].z *= scale;
			map->pixel[i][j].x += new->center.x;
			map->pixel[i][j].y += new->center.y;
			j++;
		}
		i++;
	}
}

void	rotation_x(double alpha, t_map *map, t_win *new)
{
	int		i;
	int		j;
	t_pixel tmp;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			map->pixel[i][j].x -= new->center.x;
			map->pixel[i][j].y -= new->center.y;
			tmp = map->pixel[i][j];
			map->pixel[i][j].y = tmp.y * cos(alpha) - tmp.z * sin(alpha);
			map->pixel[i][j].z = tmp.y * sin(alpha) + tmp.z * cos(alpha);
			map->pixel[i][j].x += new->center.x;
			map->pixel[i][j].y += new->center.y;
			j++;
		}
		i++;
	}
}

void	rotation_y(double alpha, t_map *map, t_win *new)
{
	int		i;
	int		j;
	t_pixel tmp;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			map->pixel[i][j].x -= new->center.x;
			map->pixel[i][j].y -= new->center.y;
			tmp = map->pixel[i][j];
			map->pixel[i][j].x = tmp.x * cos(alpha) + tmp.z * sin(alpha);
			map->pixel[i][j].z = -tmp.x * sin(alpha) + tmp.z * cos(alpha);
			map->pixel[i][j].x += new->center.x;
			map->pixel[i][j].y += new->center.y;
			j++;
		}
		i++;
	}
}

void	rotation_z(double alpha, t_map *map, t_win *new)
{
	int		i;
	int		j;
	t_pixel tmp;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			map->pixel[i][j].x -= new->center.x;
			map->pixel[i][j].y -= new->center.y;
			tmp = map->pixel[i][j];
			map->pixel[i][j].x = tmp.x * cos(alpha) - tmp.y * sin(alpha);
			map->pixel[i][j].y = tmp.x * sin(alpha) + tmp.y * cos(alpha);
			map->pixel[i][j].x += new->center.x;
			map->pixel[i][j].y += new->center.y;
			j++;
		}
		i++;
	}
}

void	translation(double delta, t_map *map, char axis, t_win *new)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			map->pixel[i][j].x -= new->center.x;
			map->pixel[i][j].y -= new->center.y;
			if (axis == 'x')
				map->pixel[i][j].x += delta;
			if (axis == 'y')
				map->pixel[i][j].y += delta;
			map->pixel[i][j].x += new->center.x;
			map->pixel[i][j].y += new->center.y;
			j++;
		}
		i++;
	}
}

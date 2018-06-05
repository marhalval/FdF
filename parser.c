/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvashchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/09 17:06:57 by hvashchu          #+#    #+#             */
/*   Updated: 2017/08/09 17:07:01 by hvashchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_list	*get_map_list(int fd)
{
	char	*line;
	t_list	*list;
	int		i;

	list = NULL;
	line = NULL;
	while ((i = get_next_line(fd, &line)) > 0)
	{
		if (ft_strlen(line) == 0)
			exit(write(2, "error: invalid map\n", 19));
		ft_lstaddback(&list, ft_lstnew(line, ft_strlen(line) + 1));
		ft_strdel(&line);
	}
	if (i == -1)
		exit(write(2, "error: invalid file\n", 20));
	return (list);
}

t_pixel	make_pixel(int x, int y, char *z)
{
	t_pixel		pixel;
	long int	check;

	check = ft_atoi_long(z);
	if (check > 2147483647 || check < -2147483648)
		exit(write(2, "error: invalid map!\n", 20));
	if (z[ft_numlen(ft_atoi(z))] != '\0')
	{
		check_color(ft_strsub(z, ft_numlen(ft_atoi(z)),
		ft_strlen(z) - ft_numlen(ft_atoi(z))));
		pixel = get_color(pixel, ft_strchr(z, 'x'));
	}
	else
	{
		pixel.rgb[0] = 255;
		pixel.rgb[1] = 255;
		pixel.rgb[2] = 255;
	}
	pixel.x = (double)x;
	pixel.y = (double)y;
	pixel.z = (double)ft_atoi(z);
	return (pixel);
}

t_map	*make_map(int width, int height, t_list *map_list)
{
	t_map	*map;
	char	**pix_arr;
	int		x;
	int		y;

	map = ft_memalloc(sizeof(t_map));
	map->width = width;
	map->height = height;
	map->pixel = (t_pixel**)malloc(sizeof(t_pixel*) * height);
	y = 0;
	while (y < height)
	{
		pix_arr = ft_strsplit(map_list->content, ' ');
		x = 0;
		map->pixel[y] = (t_pixel*)malloc(sizeof(t_pixel) * width);
		while (x < width)
		{
			map->pixel[y][x] = make_pixel(x, y, pix_arr[x]);
			x++;
		}
		ft_arrdel(pix_arr);
		map_list = map_list->next;
		y++;
	}
	return (map);
}

int		read_map(int fd, t_map **map)
{
	t_list	*map_list;
	t_list	*tmp;
	int		width;
	int		height;

	tmp = get_map_list(fd);
	map_list = tmp;
	if (map_list == NULL)
		exit(write(2, "error: empty map\n", 17));
	width = ft_arrlen(ft_strsplit(map_list->content, ' '));
	height = 0;
	while (map_list)
	{
		if (ft_arrlen(ft_strsplit(map_list->content, ' ')) == 0)
			exit(write(2, "error: empty map!\n", 17));
		if (ft_arrlen(ft_strsplit(map_list->content, ' ')) != width)
			exit(write(2, "error: invalid map\n", 19));
		height++;
		map_list = map_list->next;
	}
	*map = make_map(width, height, tmp);
	return (1);
}

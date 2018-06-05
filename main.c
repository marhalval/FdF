/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvashchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/09 17:06:48 by hvashchu          #+#    #+#             */
/*   Updated: 2017/08/09 17:06:50 by hvashchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	int		fd;
	t_map	*map;
	t_win	*new;
	t_pixel pixel;

	if (argc == 1)
		exit(write(2, "error: no file\n", 15));
	if (argc != 2)
		exit(write(2, "error: invalid input (too many files)\n", 38));
	fd = open(argv[1], O_RDONLY);
	if ((fd < 0) || !read_map(fd, &map))
		exit(write(2, "error: invalid file\n", 20));
	new = ft_memalloc(sizeof(t_win));
	init_win(new);
	new->map = map;
	adapt(new, map);
	mlx_hook(new->win, 2, 5, keyhook, new);
	mlx_loop(new->mlx);
	return (0);
}

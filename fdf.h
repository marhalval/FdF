/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvashchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/09 17:06:36 by hvashchu          #+#    #+#             */
/*   Updated: 2017/08/09 17:06:40 by hvashchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "libft/libft.h"
# include "minilibx/mlx.h"
# include <stdio.h>
# include <math.h>
# define WIDTH 1200
# define HEIGHT 800
# define ANGLE M_PI/180

typedef	struct	s_pixel
{
	double			x;
	double			y;
	double			z;
	unsigned char	rgb[3];
}				t_pixel;

typedef struct	s_map
{
	int		width;
	int		height;
	t_pixel	**pixel;
}				t_map;

typedef	struct	s_win
{
	void	*win;
	void	*mlx;
	void	*img;
	char	*line;
	int		bpp;
	int		size;
	int		endi;
	t_pixel	center;
	t_map	*map;
}				t_win;

typedef struct	s_line
{
	int		dx;
	int		dy;
	int		sx;
	int		sy;
	int		length;
	int		n;
	double	rgb_step[3];
}				t_line;

t_list			*get_map_list(int fd);
t_map			*make_map(int width, int height, t_list *map_list);
int				read_map(int fd, t_map **map);
t_pixel			make_pixel(int x, int y, char *z);
void			check_color(char const *str);
char			*get_hex(char const *str);
t_pixel			get_color(t_pixel pixel, char *str);
void			init_win(t_win *new);
void			put_pixel(t_pixel pixel, t_win *win);
void			draw_line(t_pixel p1, t_pixel p2, t_win *win);
void			draw_map(t_map *map, t_win *new);
void			adapt(t_win *win, t_map *map);
void			redraw(t_win *new, t_map *map);
void			find_center(t_win *new);
int				keyhook(int keykode, t_win *new);
void			scale(double scale, t_map *map, t_win *new);
void			rotation_x(double alpha, t_map *map, t_win *new);
void			rotation_y(double alpha, t_map *map, t_win *new);
void			rotation_z(double alpha, t_map *map, t_win *new);
void			translation(double delta, t_map *map, char axis, t_win *new);

#endif

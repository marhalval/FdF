/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvashchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 19:34:44 by hvashchu          #+#    #+#             */
/*   Updated: 2017/09/21 19:34:47 by hvashchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	*get_hex(char const *str)
{
	char	*new;
	int		length;
	int		i;

	new = (char *)malloc(sizeof(*new) * 7);
	if (new == NULL)
		return (NULL);
	i = 0;
	while (i <= 6 - ft_strlen(str))
	{
		new[i] = '0';
		i++;
	}
	while (*str != '\0')
	{
		new[i] = *str;
		i++;
		str++;
	}
	new[i] = '\0';
	return (new);
}

t_pixel	get_color(t_pixel pixel, char *str)
{
	t_pixel	new;
	int		color;

	new = pixel;
	str++;
	if (ft_strlen(str) != 6)
		str = get_hex(str);
	color = ft_atoi_base(str, 16);
	new.rgb[2] = (unsigned char)(color % 256);
	new.rgb[1] = (unsigned char)(color % 65536 / 256);
	new.rgb[0] = (unsigned char)(color / 65536);
	return (new);
}

void	check_color(char const *str)
{
	int	i;

	if (ft_strlen(str) > 9)
		exit(write(2, "error: invalid map!\n", 20));
	if (str[0] != ',' || str[1] != '0' || str[2] != 'x')
		exit(write(2, "error: invalid map!\n", 20));
	i = 3;
	while (str[i] != '\0')
	{
		if (ft_ishex(str[i]) == 0)
			exit(write(2, "error: invalid map!\n", 20));
		i++;
	}
}

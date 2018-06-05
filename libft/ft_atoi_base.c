/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvashchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 19:42:03 by hvashchu          #+#    #+#             */
/*   Updated: 2017/09/21 19:42:05 by hvashchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi_base(const char *str, int base)
{
	size_t				i;
	char				c;
	unsigned long int	res;

	i = 0;
	res = 0;
	while ((c = *(str + i)) && ((c >= 9 && c <= 13) || c == 32))
		i++;
	while ((c = ft_toupper(*(str + i)))
			&& ((c >= 48 && c < (base > 10 ? 10 : base) + 48)
			|| (c >= 65 && c <= (65 + base - 10))))
	{
		if (ft_isdigit(c))
			res = res * base + (c - '0');
		else
			res = res * base + (c - 'A' + 10);
		if (res >= 9223372036854775807)
			return (-1);
		i++;
	}
	return ((int)res);
}

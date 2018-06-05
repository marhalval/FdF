/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvashchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 14:42:10 by hvashchu          #+#    #+#             */
/*   Updated: 2017/01/12 19:59:55 by hvashchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	unsigned long int	nb;
	int					neg;

	nb = 0;
	neg = 1;
	while (*str == ' ' || *str == '\t' || *str == '\n' ||
			*str == '\f' || *str == '\r' || *str == '\v')
		str++;
	if (*str == '-')
		neg = -1;
	if (*str == '+' || *str == '-')
		str++;
	while (*str >= 48 && *str <= 57)
	{
		nb = nb * 10 + *str - 48;
		if (nb > 9223372036854775807 && neg == -1)
			return (0);
		if (nb > 9223372036854775807)
			return (-1);
		str++;
	}
	return (nb * neg);
}

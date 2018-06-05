/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvashchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 17:29:28 by hvashchu          #+#    #+#             */
/*   Updated: 2017/01/12 17:48:47 by hvashchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_revstr(char *str)
{
	char	*rev;
	int		i;
	int		j;

	i = 0;
	j = ft_strlen(str) - 1;
	rev = (char *)malloc(j + 2);
	while (j >= 0)
		rev[i++] = str[j--];
	rev[i] = '\0';
	return (rev);
}

char		*ft_itoa(int n)
{
	char	*nbr;
	int		i;
	int		sign;

	i = 0;
	sign = 1;
	nbr = (char *)malloc(ft_numlen(n) + 1);
	if (nbr == NULL)
		return (NULL);
	if (n < 0)
		sign = -1;
	if (n == 0)
		nbr[i++] = 48;
	while (n != 0)
	{
		nbr[i++] = (n % 10) * sign + 48;
		n /= 10;
	}
	if (sign == -1)
		nbr[i++] = '-';
	nbr[i] = '\0';
	nbr = ft_revstr(nbr);
	return (nbr);
}

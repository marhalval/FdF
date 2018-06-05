/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvashchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 20:19:32 by hvashchu          #+#    #+#             */
/*   Updated: 2016/12/27 23:28:48 by hvashchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	const char	*out;
	const char	*tmp;
	size_t		i;

	if (*little == '\0')
		return (char *)big;
	while (*big != '\0' && len > 0)
	{
		if (*big == *little)
		{
			out = big;
			tmp = little;
			i = len;
			while (*out++ == *tmp++ && i > 0)
			{
				i--;
				if (*tmp == '\0')
					return (char *)big;
			}
		}
		big++;
		len--;
	}
	return (0);
}

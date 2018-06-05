/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvashchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 14:49:09 by hvashchu          #+#    #+#             */
/*   Updated: 2016/12/23 19:54:34 by hvashchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	const char	*out;
	const char	*tmp;

	if (*little == '\0')
		return (char *)big;
	while (*big != 0)
	{
		if (*big == *little)
		{
			out = big;
			tmp = little;
			while (*out++ == *tmp++)
			{
				if (*tmp == '\0')
					return (char *)big;
			}
		}
		big++;
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvashchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 21:32:17 by hvashchu          #+#    #+#             */
/*   Updated: 2017/01/10 18:54:27 by hvashchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*tdst;
	unsigned char	*tsrc;
	size_t			i;

	i = 0;
	tdst = (unsigned char *)dst;
	tsrc = (unsigned char *)src;
	if (tdst > tsrc)
	{
		while (len != 0)
		{
			tdst[len - 1] = tsrc[len - 1];
			len--;
		}
	}
	else
	{
		while (i < len)
		{
			tdst[i] = tsrc[i];
			i++;
		}
	}
	return (dst);
}

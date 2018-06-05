/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvashchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 15:58:50 by hvashchu          #+#    #+#             */
/*   Updated: 2017/01/12 17:31:21 by hvashchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*dsttmp;
	unsigned char	*srctmp;

	i = 0;
	dsttmp = (unsigned char *)dst;
	srctmp = (unsigned char *)src;
	while (i < n)
	{
		dsttmp[i] = srctmp[i];
		i++;
	}
	return (dst);
}

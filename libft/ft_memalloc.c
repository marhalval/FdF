/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvashchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 19:09:49 by hvashchu          #+#    #+#             */
/*   Updated: 2017/01/12 19:42:43 by hvashchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*out;

	out = (char *)malloc(size);
	if (out == NULL)
		return (NULL);
	while (size > 0)
	{
		out[size - 1] = 0;
		size--;
	}
	return ((void *)out);
}

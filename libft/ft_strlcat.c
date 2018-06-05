/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvashchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 19:07:23 by hvashchu          #+#    #+#             */
/*   Updated: 2017/01/13 22:35:06 by hvashchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	idst;
	size_t	isrc;

	idst = ft_strlen(dst);
	isrc = ft_strlen(src);
	if (size < idst + 1)
		return (size + isrc);
	if (size > idst + 1)
		ft_strncat(dst, src, size - idst - 1);
	return (idst + isrc);
}

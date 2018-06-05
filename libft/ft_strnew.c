/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvashchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 15:58:25 by hvashchu          #+#    #+#             */
/*   Updated: 2016/12/06 15:20:30 by hvashchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*new;

	new = (char *)malloc(sizeof(*new) * (size + 1));
	if (new == NULL)
		return (NULL);
	else
	{
		new[size] = '\0';
		while (size-- > 0)
			new[size] = '\0';
		return (new);
	}
}

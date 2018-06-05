/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvashchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 15:41:06 by hvashchu          #+#    #+#             */
/*   Updated: 2016/12/13 15:56:57 by hvashchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	char	*out;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	join = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (join == NULL)
		return (NULL);
	out = join;
	while (*s1 != '\0')
	{
		*join = *s1;
		join++;
		s1++;
	}
	while (*s2 != '\0')
	{
		*join = *s2;
		join++;
		s2++;
	}
	*join = '\0';
	return (out);
}

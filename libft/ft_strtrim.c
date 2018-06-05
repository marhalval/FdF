/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvashchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 17:30:19 by hvashchu          #+#    #+#             */
/*   Updated: 2016/12/27 21:47:21 by hvashchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		is_trim(char c)
{
	char	*trims;

	trims = " \f\n\r\t\v";
	while (*trims)
	{
		if (*trims == c)
			return (1);
		trims++;
	}
	return (0);
}

char			*ft_strtrim(char const *s)
{
	char	*fresh;
	int		start;
	int		end;
	int		len;
	int		i;

	if (s == NULL)
		return (NULL);
	len = ft_strlen(s) - 1;
	i = 0;
	while (is_trim(s[i]) && i <= len)
		i++;
	start = i;
	while (len != start - 1 && is_trim(s[len]))
		len--;
	end = len;
	fresh = (char *)malloc(end - start + 2);
	if (fresh == NULL)
		return (NULL);
	i = 0;
	while (start <= end)
		fresh[i++] = s[start++];
	fresh[i] = '\0';
	return (fresh);
}

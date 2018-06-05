/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvashchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 20:09:50 by hvashchu          #+#    #+#             */
/*   Updated: 2017/01/12 17:37:31 by hvashchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f) (unsigned int, char))
{
	char	*fresh;
	size_t	i;

	if (s == NULL)
		return (NULL);
	fresh = (char *)malloc((ft_strlen(s) + 1) * sizeof(*fresh));
	if (fresh == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		fresh[i] = f(i, s[i]);
		i++;
	}
	fresh[i] = '\0';
	return (fresh);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvashchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 18:55:08 by hvashchu          #+#    #+#             */
/*   Updated: 2017/01/12 17:37:19 by hvashchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f) (char))
{
	char	*fresh;
	size_t	i;

	if (s == NULL || f == NULL)
		return (NULL);
	fresh = (char *)malloc((ft_strlen(s) + 1) * sizeof(*fresh));
	if (fresh == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		fresh[i] = f(s[i]);
		i++;
	}
	fresh[i] = '\0';
	return (fresh);
}

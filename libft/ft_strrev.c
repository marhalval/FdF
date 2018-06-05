/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvashchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 17:18:08 by hvashchu          #+#    #+#             */
/*   Updated: 2017/01/12 17:49:11 by hvashchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char const *str)
{
	char	*rev;
	int		i;
	int		j;

	if (str == NULL)
		return (NULL);
	i = 0;
	j = ft_strlen(str) - 1;
	rev = (char *)malloc(j + 2);
	if (rev == NULL)
		return (NULL);
	rev[i] = str[j];
	while (j >= 0)
		rev[i++] = str[j--];
	rev[i++] = '\0';
	return (rev);
}

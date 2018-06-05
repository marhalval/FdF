/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvashchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/27 18:10:29 by hvashchu          #+#    #+#             */
/*   Updated: 2017/01/12 17:45:54 by hvashchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		n_words(char const *s, char c)
{
	size_t	n;
	size_t	i;

	n = 0;
	i = 0;
	while (s[i] == c)
		i++;
	while (s[i] != '\0')
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			n++;
		i++;
	}
	return (n);
}

static void		easy_cut(char **array, char const *s, char c, size_t *i)
{
	size_t	len;
	size_t	j;
	size_t	k;

	len = 0;
	k = 0;
	while (s[k])
	{
		while (s[k] == c)
			k++;
		while (s[k] != c && s[k] != '\0')
		{
			len++;
			k++;
		}
		if (len > 0)
		{
			array[*i] = (char *)malloc(sizeof(**array) * (len + 1));
			j = 0;
			while (len != 0)
				array[*i][j++] = s[k - len--];
			array[*i][j] = '\0';
			*i += 1;
		}
	}
}

char			**ft_strsplit(char const *s, char c)
{
	char	**array;
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	array = (char **)malloc(sizeof(*array) * (n_words(s, c) + 1));
	if (!array)
		return (NULL);
	easy_cut(array, s, c, &i);
	array[i] = NULL;
	return (array);
}

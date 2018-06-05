/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvashchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 16:24:35 by hvashchu          #+#    #+#             */
/*   Updated: 2017/01/10 18:53:14 by hvashchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstsplit(char const *str, char c)
{
	t_list	**new;
	size_t	l;

	l = 0;
	new = (t_list **)malloc(sizeof(*new));
	*new = NULL;
	while (*str != '\0')
	{
		while (*str == c)
			str++;
		while (*str != c && *str != '\0')
		{
			l++;
			str++;
		}
		str -= l;
		if (l > 0)
		{
			ft_lstaddback(new, ft_lstnew(str, l));
			str += l;
			l = 0;
		}
	}
	return (*new);
}

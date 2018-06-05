/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvashchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 17:12:29 by hvashchu          #+#    #+#             */
/*   Updated: 2017/01/13 22:23:35 by hvashchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	**new;

	new = (t_list **)malloc(sizeof(*new));
	*new = NULL;
	while (lst)
	{
		ft_lstaddback(new, f(lst));
		lst = lst->next;
	}
	return (*new);
}

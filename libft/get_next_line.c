/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvashchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 16:05:06 by hvashchu          #+#    #+#             */
/*   Updated: 2017/07/05 16:05:09 by hvashchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_lst	*check_fd(const int fd, t_lst **gnl)
{
	t_lst	*tmp;
	t_lst	*new;

	tmp = *gnl;
	while (tmp)
	{
		if (tmp->fd == fd)
			return (tmp);
		tmp = tmp->next;
	}
	new = (t_lst *)malloc(sizeof(*new));
	if (new == NULL)
		return (NULL);
	new->buf = NULL;
	new->fd = fd;
	new->next = *gnl;
	*gnl = new;
	return (new);
}

int		get_line(t_lst *gnl, char **line)
{
	size_t	index;
	char	*tmp;

	if (ft_strlen(gnl->buf) != 0)
	{
		if (ft_strchr(gnl->buf, '\n'))
		{
			*line = ft_strsub(gnl->buf, 0, ft_strchr(gnl->buf, 10) - gnl->buf);
			index = ft_strchr(gnl->buf, '\n') - gnl->buf + 1;
			tmp = gnl->buf;
			gnl->buf = ft_strsub(gnl->buf, index, ft_strlen(gnl->buf) - index);
			ft_strdel(&tmp);
		}
		else
		{
			*line = ft_strdup(gnl->buf);
			ft_strdel(&gnl->buf);
		}
	}
	else
		return (0);
	return (1);
}

int		get_buf(t_lst *gnl, char **line)
{
	char	buffer[BUFF_SIZE + 1];
	char	*tmp;
	int		n_read;

	buffer[BUFF_SIZE] = '\0';
	if (gnl->buf == NULL)
		gnl->buf = ft_strnew(BUFF_SIZE);
	if (!ft_strchr(gnl->buf, '\n'))
	{
		while ((n_read = read(gnl->fd, buffer, BUFF_SIZE)) > 0)
		{
			if (n_read == -1)
				return (-1);
			buffer[n_read] = '\0';
			tmp = gnl->buf;
			gnl->buf = ft_strjoin(tmp, buffer);
			ft_strdel(&tmp);
			if (ft_strchr(gnl->buf, '\n'))
				break ;
		}
	}
	return (get_line(gnl, line));
}

int		get_next_line(const int fd, char **line)
{
	static t_lst	*gnl = NULL;

	if (fd == -1 || read(fd, NULL, 0) == -1)
		return (-1);
	if (gnl == NULL)
	{
		if ((gnl = (t_lst*)malloc(sizeof(t_lst))) == NULL)
			return (-1);
		gnl->buf = NULL;
		gnl->fd = fd;
		gnl->next = NULL;
	}
	if (gnl->fd != fd)
		return (get_buf(check_fd(fd, &gnl), line));
	else
		return (get_buf(gnl, line));
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanylch <mdanylch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 17:30:51 by mdanylch          #+#    #+#             */
/*   Updated: 2019/07/28 16:05:34 by mdanylch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_gnl	*ft_newlist(int fd, t_gnl **head)
{
	t_gnl	*tmp;

	if (!(*head))
	{
		tmp = (t_gnl*)malloc(sizeof(t_gnl));
		tmp->fd = fd;
		tmp->buf = NULL;
		tmp->next = NULL;
		return (*head = tmp);
	}
	tmp = *head;
	while (tmp != NULL)
	{
		if (tmp->fd == fd)
			return (tmp);
		else
			tmp = tmp->next;
	}
	tmp = ft_newlist(fd, &tmp);
	tmp->next = *head;
	*head = tmp;
	return (*head);
}

char	*ft_work(t_gnl *list, char *buf)
{
	char	*tmp;
	char	*cut;
	char	*clear;
	char	*buf_tmp;

	tmp = ft_strnew(0);
	while ((cut = ft_strchr(buf, '\n')) == NULL)
	{
		CLEAR(clear, tmp, ft_strjoin(tmp, buf));
		ft_strclr(buf);
		if ((read(list->fd, buf, BUFF_SIZE)) == 0)
		{
			ft_strdel(&list->buf);
			return (tmp);
		}
	}
	buf_tmp = ft_strsub(buf, 0, ft_strlen(buf) - ft_strlen(cut));
	CLEAR(clear, tmp, ft_strjoin(tmp, buf_tmp));
	ft_strdel(&buf_tmp);
	ft_strdel(&list->buf);
	list->buf = ft_strsub(buf, ft_strlen(buf) - ft_strlen(cut) + 1,
			BUFF_SIZE + 1);
	return (tmp);
}

int		get_next_line(const int fd, char **line)
{
	static t_gnl	*list = NULL;
	t_gnl			*list_tmp;
	char			buf[BUFF_SIZE + 1];

	if (fd < 0 || read(fd, 0, 0) != 0 || !line || BUFF_SIZE < 1)
		return (-1);
	list_tmp = ft_newlist(fd, &list);
	ft_bzero(buf, BUFF_SIZE + 1);
	if (list_tmp->buf && (ft_strlen(list_tmp->buf)))
		ft_strcpy(buf, list_tmp->buf);
	else if ((read(fd, buf, BUFF_SIZE)) == 0)
	{
		ft_strdel(&list_tmp->buf);
		return (0);
	}
	*line = ft_work(list_tmp, buf);
	return (1);
}

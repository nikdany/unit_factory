/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanylch <mdanylch@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 21:25:48 by mdanylch          #+#    #+#             */
/*   Updated: 2019/04/26 21:25:55 by mdanylch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_gnl	*ft_newlist(int fd, t_gnl **head)
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

static size_t	ft_str_n(const char *s, char c)
{
	size_t	i;

	i = 1;
	while (s[i - 1] != '\0' && s[i - 1] != c)
		i++;
	if (s[i - 1] == '\0')
		return (0);
	return (i);
}

static char		*ft_del_str(char *s2, char *s3)
{
	char *s1;

	s1 = s2;
	ft_strdel(&s1);
	return (s3);
}

static char		*ft_work(t_gnl *list)
{
	size_t	i;
	char	*tmp;
	char	*line;

	line = ft_strnew(BUFF_SIZE);
	while (!(i = ft_str_n(list->buf, '\n')))
	{
		line = ft_del_str(line, ft_strjoin(line, list->buf));
		ft_strclr(list->buf);
		if (!read(list->fd, list->buf, BUFF_SIZE))
		{
			ft_strdel(&list->buf);
			return (line);
		}
	}
	tmp = ft_strsub(list->buf, 0, i - 1);
	line = ft_del_str(line, ft_strjoin(line, tmp));
	tmp = ft_del_str(tmp, ft_strsub(list->buf, i, BUFF_SIZE - i));
	ft_strclr(list->buf);
	list->buf = ft_strcpy(list->buf, tmp);
	ft_strdel(&tmp);
	return (line);
}

int				get_next_line(const int fd, char **line)
{
	static t_gnl	*list = NULL;
	t_gnl			*list_tmp;

	if (fd < 0 || read(fd, 0, 0) != 0 || !line || BUFF_SIZE < 1)
		return (-1);
	list_tmp = ft_newlist(fd, &list);
	if (list_tmp->buf == NULL)
		list_tmp->buf = ft_strnew(BUFF_SIZE + 1);
	if (!(ft_strlen(list_tmp->buf)) && !(read(fd, list_tmp->buf, BUFF_SIZE)))
	{
		ft_strdel(&list_tmp->buf);
		return (0);
	}
	*line = ft_work(list_tmp);
	return (1);
}

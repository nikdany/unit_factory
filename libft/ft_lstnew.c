/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanylch <mdanylch@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 14:00:31 by mdanylch          #+#    #+#             */
/*   Updated: 2019/01/24 14:14:56 by mdanylch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*cell;

	if (!(cell = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	if (!content)
	{
		cell->content = NULL;
		cell->content_size = 0;
	}
	else
	{
		if (!(cell->content = (void*)malloc(content_size)))
		{
			free(cell);
			return (NULL);
		}
		ft_memcpy(cell->content, content, content_size);
		cell->content_size = content_size;
	}
	cell->next = NULL;
	return (cell);
}

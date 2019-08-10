/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanylch <mdanylch@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 18:22:53 by mdanylch          #+#    #+#             */
/*   Updated: 2019/01/24 18:32:10 by mdanylch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*tmp;
	t_list	*head;

	if (!lst || !f)
		return (NULL);
	tmp = f(lst);
	head = tmp;
	while (lst->next)
	{
		lst = lst->next;
		if (!(tmp->next = f(lst)))
		{
			free(tmp->next);
			return (NULL);
		}
		tmp = tmp->next;
	}
	return (head);
}

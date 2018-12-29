/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amassnao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 15:17:08 by amassnao          #+#    #+#             */
/*   Updated: 2018/10/07 18:47:58 by amassnao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *list;
	t_list *tmp;
	t_list *p;

	list = NULL;
	while (lst != NULL)
	{
		tmp = (t_list *)malloc(sizeof(t_list));
		tmp->content = (*f)(lst)->content;
		tmp->content_size = (*f)(lst)->content_size;
		tmp->next = NULL;
		if (list == NULL)
		{
			list = tmp;
			p = list;
		}
		else
		{
			list->next = tmp;
			list = list->next;
		}
		lst = lst->next;
	}
	return (p);
}

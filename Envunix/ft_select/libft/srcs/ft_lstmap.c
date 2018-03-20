/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flemaist <flemaist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/27 20:50:48 by flemaist          #+#    #+#             */
/*   Updated: 2014/11/27 20:50:49 by flemaist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*list;
	t_list	*tmp;

	list = NULL;
	tmp = NULL;
	while (lst != NULL && f)
	{
		if (tmp == NULL)
		{
			list = ft_lstnew(lst->content, lst->content_size);
			list = f(list);
			tmp = list;
		}
		else
		{
			list->next = ft_lstnew(lst->content, lst->content_size);
			list->next = f(list->next);
			list = list->next;
		}
		lst = lst->next;
	}
	return (tmp);
}

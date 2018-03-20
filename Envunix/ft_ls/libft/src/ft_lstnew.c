/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flemaist <flemaist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/27 18:50:27 by flemaist          #+#    #+#             */
/*   Updated: 2014/11/27 18:50:28 by flemaist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(const void *content, size_t content_size)
{
	t_list		*n_list;

	if ((n_list = (t_list *)malloc(sizeof(t_list))) == NULL)
		return (NULL);
	if (content == NULL)
	{
		n_list->content = NULL;
		n_list->content_size = 0;
	}
	else
	{
		if ((n_list->content = ft_memalloc(content_size)) == NULL)
			return (NULL);
		ft_memcpy(n_list->content, content, content_size);
		n_list->content_size = content_size;
	}
	n_list->next = NULL;
	return (n_list);
}

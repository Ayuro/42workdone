/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstelem.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flemaist <flemaist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/27 18:50:14 by flemaist          #+#    #+#             */
/*   Updated: 2014/11/27 18:50:15 by flemaist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstelem(t_list *begin_list, size_t n)
{
	size_t		i;
	t_list		*cur_list;

	i = 0;
	cur_list = begin_list;
	while (i < n && cur_list != NULL)
	{
		cur_list = cur_list->next;
		i++;
	}
	return (cur_list);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flemaist <flemaist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/27 18:50:57 by flemaist          #+#    #+#             */
/*   Updated: 2014/11/27 18:50:59 by flemaist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_lstsize(t_list *alst)
{
	t_list		*cur_list;
	size_t		size;

	size = 0;
	cur_list = alst;
	while (cur_list != NULL)
	{
		cur_list = cur_list->next;
		size++;
	}
	return (size);
}

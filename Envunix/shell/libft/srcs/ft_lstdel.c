/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flemaist <flemaist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/27 18:49:32 by flemaist          #+#    #+#             */
/*   Updated: 2014/11/27 18:49:36 by flemaist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list		*cur_list;
	t_list		*next_list;

	if (alst == NULL)
		return ;
	cur_list = *alst;
	while (cur_list != NULL)
	{
		next_list = cur_list->next;
		ft_lstdelone(&cur_list, del);
		cur_list = next_list;
	}
	*alst = NULL;
}

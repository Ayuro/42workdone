/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprint_str.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flemaist <flemaist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/27 18:50:43 by flemaist          #+#    #+#             */
/*   Updated: 2014/11/27 18:50:44 by flemaist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstprint_str(t_list **list, char c)
{
	t_list		*cur_list;

	cur_list = *list;
	while (cur_list != NULL)
	{
		if (cur_list->content != NULL)
			ft_putstr(cur_list->content);
		ft_putchar(c);
		cur_list = cur_list->next;
	}
}

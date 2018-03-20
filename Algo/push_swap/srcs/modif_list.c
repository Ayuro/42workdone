/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modif_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flemaist <flemaist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/30 18:14:48 by flemaist          #+#    #+#             */
/*   Updated: 2014/10/30 18:14:52 by flemaist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void		ft_swap(t_list **begin, const char *str)
{
	t_list	*tmp;
	t_list	*ref;

	tmp = *begin;
	ref = tmp->next;
	tmp->next = ref->next;
	ref->next = tmp;
	*begin = ref;
	write(1, str, ft_strlen(str));
	write(1, " ", 1);
}

void		ft_push(t_list **take, t_list **push, const char *str)
{
	t_list	*tmp;
	t_list	*tmp2;

	tmp = *take;
	tmp2 = tmp->next;
	tmp->next = *push;
	*take = tmp2;
	*push = tmp;
	write(1, str, ft_strlen(str));
	write(1, " ", 1);
}

void		ft_rotate_ftl(t_list **begin, const char *str)
{
	t_list	*tmp;
	t_list	*tmp2;
	t_list	*tmp3;

	tmp = *begin;
	tmp2 = tmp;
	tmp3 = tmp->next;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = tmp2;
	tmp2->next = NULL;
	*begin = tmp3;
	write(1, str, ft_strlen(str));
	write(1, " ", 1);
}

void		ft_rotate_ltf(t_list **begin, const char *str)
{
	t_list	*tmp;
	t_list	*tmp2;
	t_list	*tmp3;

	tmp = *begin;
	tmp2 = tmp;
	while (tmp->next)
	{
		tmp3 = tmp;
		tmp = tmp->next;
	}
	tmp->next = tmp2;
	tmp3->next = NULL;
	*begin = tmp;
	write(1, str, ft_strlen(str));
	write(1, " ", 1);
}

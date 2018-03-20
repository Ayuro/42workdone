/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flemaist <flemaist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/30 18:07:51 by flemaist          #+#    #+#             */
/*   Updated: 2014/10/30 18:07:53 by flemaist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int		ft_get_status(t_list **l_a, t_list *min)
{
	t_list		*tmp;
	int			max;
	int			inc;

	inc = 1;
	max = 0;
	tmp = *l_a;
	while (tmp)
	{
		max++;
		tmp = tmp->next;
	}
	tmp = *l_a;
	while (tmp != min)
	{
		inc++;
		tmp = tmp->next;
	}
	return ((max / inc));
}

t_list	*ft_find_min(t_list **l_a)
{
	t_list		*min;
	t_list		*tmp;

	tmp = *l_a;
	min = tmp;
	while (tmp->next)
	{
		if (min->val > tmp->next->val)
			min = tmp->next;
		tmp = tmp->next;
	}
	return (min);
}

void	ft_swap_list(t_list **l_a, t_list **l_b)
{
	t_list		*min;
	t_list		*tmp;
	int			status;

	tmp = *l_a;
	min = ft_find_min(l_a);
	status = ft_get_status(l_a, min);
	if (tmp->next->next)
	{
		if (tmp->val > tmp->next->val && tmp->next->next->val > tmp->val)
			ft_swap(l_a, "sa");
		while (*l_a != min)
		{
			if (status >= 2)
				ft_rotate_ftl(l_a, "ra");
			else
				ft_rotate_ltf(l_a, "rra");
		}
		if ((ft_parse_list(*l_a)))
			ft_push(l_a, l_b, "pb");
	}
	else if (tmp->val > tmp->next->val)
		ft_swap(l_a, "sa");
}

int		ft_parse_list(t_list *l_a)
{
	int			check;
	t_list		*tmp;

	check = 0;
	tmp = l_a;
	while (tmp && tmp->next)
	{
		if (tmp->val > tmp->next->val)
			check = 1;
		tmp = tmp->next;
	}
	return (check);
}

void	ft_pushswap(char **av)
{
	t_list		*l_a;
	t_list		*l_b;

	l_a = NULL;
	l_b = NULL;
	ft_fill_list(&l_a, av);
	if (!(ft_parse_list(l_a)))
		exit(EXIT_SUCCESS);
	while ((ft_parse_list(l_a)))
		ft_swap_list(&l_a, &l_b);
	while (l_b)
		ft_push(&l_b, &l_a, "pa");
}

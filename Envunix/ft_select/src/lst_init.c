/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flemaist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 14:05:41 by flemaist          #+#    #+#             */
/*   Updated: 2016/11/04 14:05:42 by flemaist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

t_select	*t_select_init(char *name, t_select *prev)
{
	t_select	*new;

	if ((new = (t_select*)malloc(sizeof(t_select))) == NULL)
		return (ft_display_malloc_fail("lst.c", 20));
	new->name = ft_strdup(name);
	new->select = 0;
	new->print = 1;
	new->nxt = NULL;
	new->prv = (prev == NULL) ? NULL : prev;
	if (prev != NULL)
		prev->nxt = new;
	return (new);
}

void		free_lst(t_select *fst)
{
	t_select	*last;

	last = fst->prv;
	while (fst != last)
	{
		fst = fst->nxt;
		ft_strclr(fst->prv->name);
		free(fst->prv->name);
		fst->prv->select = 0;
		fst->prv->print = 0;
		fst->prv->nxt = NULL;
		fst->prv->prv = NULL;
		free(fst->prv);
		fst->prv = NULL;
	}
	ft_strclr(fst->name);
	free(fst->name);
	fst->select = 0;
	fst->print = 0;
	fst->nxt = NULL;
	free(fst);
	return ;
}

t_select	*put_to_lst(char **av, int ac)
{
	t_select	*fst;
	t_select	*travel;
	int			i;

	i = 1;
	fst = NULL;
	while (i < ac)
	{
		if (fst == NULL)
		{
			if ((fst = t_select_init(av[i], NULL)) == NULL)
				return (NULL);
			travel = fst;
		}
		else if ((travel = t_select_init(av[i], travel)) == NULL)
		{
			free_lst(fst);
			return (NULL);
		}
		i++;
	}
	fst->prv = travel;
	travel->nxt = fst;
	return (fst);
}

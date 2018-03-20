/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flemaist <flemaist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/30 18:14:14 by flemaist          #+#    #+#             */
/*   Updated: 2014/10/30 18:14:39 by flemaist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_list		*ft_create_elem(t_list *l_a, char *av)
{
	t_list			*new;

	if ((new = (t_list *)malloc(sizeof(t_list))) == NULL)
	{
		write(2, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	new->val = ft_atoi(av);
	new->next = l_a;
	return (new);
}

void		ft_fill_list(t_list **l_a, char **av)
{
	int				i;

	i = 1;
	while (av[i])
		i++;
	i--;
	while (i > 0)
	{
		*l_a = ft_create_elem(*l_a, av[i]);
		i--;
	}
}

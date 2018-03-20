/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flemaist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 13:20:42 by flemaist          #+#    #+#             */
/*   Updated: 2017/01/11 13:20:44 by flemaist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_tabdel(char **as)
{
	int		i;

	i = 0;
	if (as == NULL)
		return ;
	while (as[i])
	{
		if (as[i])
			free(as[i]);
		as[i] = NULL;
		i++;
	}
	free(as);
	as = NULL;
}

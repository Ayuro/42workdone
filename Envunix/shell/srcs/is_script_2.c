/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_script_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flemaist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 15:07:51 by flemaist          #+#    #+#             */
/*   Updated: 2017/01/11 15:07:51 by flemaist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int			is_structure_boucle(char *boucle)
{
	int		i;

	i = 0;
	if (!boucle)
		return (0);
	while (boucle[i] && ft_isspace(boucle[i]))
		i++;
	if (ft_strncmp(boucle + i, "for", 3) == 0 && ft_isspace(boucle[3 + i]))
		return (FOR);
	if (ft_strncmp(boucle + i, "while", 5) == 0 && ft_isspace(boucle[5 + i]))
		return (WHILE);
	if (ft_strncmp(boucle + i, "until", 5) == 0 && ft_isspace(boucle[5 + i]))
		return (UNTIL);
	return (0);
}

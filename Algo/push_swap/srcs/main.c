/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flemaist <flemaist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/30 18:05:21 by flemaist          #+#    #+#             */
/*   Updated: 2014/10/30 18:05:22 by flemaist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int				main(int ac, char **av)
{
	if (ac < 1)
	{
		write(2, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	else if (ac == 1 || ac == 2)
		exit(EXIT_SUCCESS);
	ft_pushswap(av);
	write(1, "\n", 1);
	return (0);
}

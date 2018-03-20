/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flemaist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/25 15:43:17 by flemaist          #+#    #+#             */
/*   Updated: 2017/07/25 15:43:20 by flemaist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"

void	ft_error(int error)
{
	if (error == 21)
		ft_putstr_err(ERR_DIR);
}

char	exit_failure_1s(char *s, char exitmode)
{
	ft_putstr_err(s);
	if (exitmode == TRUE)
		exit(0);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_err.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flemaist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 14:09:26 by flemaist          #+#    #+#             */
/*   Updated: 2017/01/13 14:09:26 by flemaist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"
#include "../include/colors.h"

int		env_err(void)
{
	ft_putstr_fd(C_RED, get_fd(-1));
	ft_putendl_fd("Environnement vide, le programme ne peut fonctionner",
	get_fd(-1));
	ft_putendl_fd("Fermeture !", get_fd(-1));
	return (0);
}

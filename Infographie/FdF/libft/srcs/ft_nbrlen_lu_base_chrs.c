/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen_lu_base_chrs.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flemaist <flemaist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/16 18:46:54 by flemaist          #+#    #+#             */
/*   Updated: 2015/05/16 18:46:54 by flemaist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_nbrlen_lu_base_chrs(unsigned long nb, char *base)
{
	return (ft_nbrlen_lu_base(nb, ft_strlen(base)));
}

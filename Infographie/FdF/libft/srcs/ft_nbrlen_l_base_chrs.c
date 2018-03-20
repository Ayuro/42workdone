/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen_l_base_chrs.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flemaist <flemaist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/16 18:46:47 by flemaist          #+#    #+#             */
/*   Updated: 2015/05/16 18:46:49 by flemaist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_nbrlen_l_base_chrs(long nb, char *base)
{
	return (ft_nbrlen_l_base(nb, ft_strlen(base)));
}

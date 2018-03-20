/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_malloc_fail.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flemaist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 14:17:24 by flemaist          #+#    #+#             */
/*   Updated: 2016/11/04 14:17:27 by flemaist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_display_malloc_fail(char *file, int line)
{
	ft_putstr("Malloc failed on line ");
	ft_putnbr(line);
	ft_putstr(" from file ");
	ft_putendl(file);
	return (NULL);
}

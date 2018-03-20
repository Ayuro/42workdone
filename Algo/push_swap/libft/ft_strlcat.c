/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flemaist <flemaist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 10:39:28 by flemaist          #+#    #+#             */
/*   Updated: 2013/12/23 13:51:33 by flemaist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned int	i;
	unsigned int	lendst;

	i = 0;
	lendst = ft_strlen(dst);
	if (size > lendst)
	{
		while (src[i] != '\0' && size - 1 > lendst + i)
		{
			dst[lendst + i] = src[i];
			i++;
		}
		dst[lendst + i] = '\0';
		return (lendst + ft_strlen(src));
	}
	else
		return (size + ft_strlen(src));
}

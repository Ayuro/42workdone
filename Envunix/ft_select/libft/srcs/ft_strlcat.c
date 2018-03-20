/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flemaist <flemaist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/27 19:34:39 by flemaist          #+#    #+#             */
/*   Updated: 2014/11/27 19:34:40 by flemaist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

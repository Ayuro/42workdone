/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flemaist <flemaist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/27 19:36:18 by flemaist          #+#    #+#             */
/*   Updated: 2014/11/27 19:36:19 by flemaist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	char	*cp;

	cp = dst;
	while (n > 0)
	{
		if (*src != '\0')
			*cp++ = *(char *)src++;
		else
			*cp++ = '\0';
		n--;
	}
	return (dst);
}

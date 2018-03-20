/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flemaist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/19 16:05:31 by flemaist          #+#    #+#             */
/*   Updated: 2016/05/19 16:05:34 by flemaist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_realloc(char *s1, size_t size)
{
	char	*tmp;

	if (!s1)
		tmp = ft_strnew(size);
	else
	{
		tmp = ft_strnew(ft_strlen(s1) + size);
		ft_strcpy(tmp, s1);
		free(s1);
	}
	return (tmp);
}

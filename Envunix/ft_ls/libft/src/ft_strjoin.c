/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flemaist <flemaist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/27 19:34:23 by flemaist          #+#    #+#             */
/*   Updated: 2014/11/27 19:34:24 by flemaist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(const char *s1, const char *s2)
{
	int		len;
	char	*s3;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len = ft_strlen((char *)s1) + ft_strlen((char *)s2);
	if ((s3 = ft_strnew(len)) == NULL)
		return (NULL);
	ft_strcpy((char *)s3, (char *)s1);
	ft_strcat((char *)s3, (char *)s2);
	return (s3);
}

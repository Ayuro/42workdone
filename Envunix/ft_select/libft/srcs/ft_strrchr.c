/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flemaist <flemaist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/27 19:37:14 by flemaist          #+#    #+#             */
/*   Updated: 2014/11/27 19:37:15 by flemaist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	int		ret;
	int		l;

	if (s == NULL)
		return (NULL);
	if (c == '\0')
	{
		l = ft_strlen(s);
		return ((char *)s + l);
	}
	ret = -1;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			ret = i;
		i++;
	}
	if (ret != -1)
		return ((char *)s + ret);
	return (NULL);
}
